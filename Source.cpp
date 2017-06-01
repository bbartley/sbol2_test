/**
 * @file    test_sequence_assembly.cpp
 * @brief
 * @author  Bryan Bartley
 * @email   bartleyba@sbolstandard.org
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBOL.  Please visit http://sbolstandard.org for more
 * information about SBOL, and the latest version of libSBOL.
 *
 *  Copyright 2016 University of Washington, WA, USA
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ------------------------------------------------------------------------->*/

#define BASE_URI "http://sys-bio.org"

#include "sbol.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace sbol;

int main()
{
    setHomespace(BASE_URI);
    Document& doc = *new Document();
    
    ComponentDefinition& gene = *new ComponentDefinition("BB0001");
    ComponentDefinition& promoter = *new ComponentDefinition("R0010");
    ComponentDefinition& RBS = *new ComponentDefinition("B0032");
    ComponentDefinition& CDS = *new ComponentDefinition("E0040");
    ComponentDefinition& terminator = *new ComponentDefinition("B0012");
    
    promoter.roles.set(SO_PROMOTER);
    CDS.roles.set(SO_CDS);
    RBS.roles.set(SO_RBS);
    terminator.roles.set(SO_TERMINATOR);
    
    doc.add<ComponentDefinition>(gene);
    doc.add<ComponentDefinition>(promoter);
    doc.add<ComponentDefinition>(CDS);
    doc.add<ComponentDefinition>(RBS);
    doc.add<ComponentDefinition>(terminator);
    
    gene.assemble({ &promoter, &RBS, &CDS, &terminator});
    
    Component& first = gene.getFirstComponent();
    cout << first.identity.get() << endl;
    Component& last = gene.getLastComponent();
    cout << last.identity.get() << endl;
    
//    Sequence& promoter_seq = *new Sequence("R0010", "ggctgca");
//    Sequence& RBS_seq = *new Sequence("B0032", "aattatataaa");
//    Sequence& CDS_seq = *new Sequence("E0040", "atgtaa");
//    Sequence& terminator_seq = *new Sequence("B0012", "attcga");
//    Sequence& gene_seq = *new Sequence("BB0001");
    
    Sequence& promoter_seq = *new Sequence("R0010", "caatacgcaaaccgcctctccccgcgcgttggccgattcattaatgcagctggcacgacaggtttcccgactggaaagcgggcagtgagcgcaacgcaattaatgtgagttagctcactcattaggcaccccaggctttacactttatgcttccggctcgtatgttgtgtggaattgtgagcggataacaatttcacaca");
    Sequence& RBS_seq = *new Sequence("B0032", "tcacacaggaaag");
    Sequence& CDS_seq = *new Sequence("E0040", "atgcgtaaaggagaagaacttttcactggagttgtcccaattcttgttgaattagatggtgatgttaatgggcacaaattttctgtcagtggagagggtgaaggtgatgcaacatacggaaaacttacccttaaatttatttgcactactggaaaactacctgttccatggccaacacttgtcactactttcggttatggtgttcaatgctttgcgagatacccagatcatatgaaacagcatgactttttcaagagtgccatgcccgaaggttatgtacaggaaagaactatatttttcaaagatgacgggaactacaagacacgtgctgaagtcaagtttgaaggtgatacccttgttaatagaatcgagttaaaaggtattgattttaaagaagatggaaacattcttggacacaaattggaatacaactataactcacacaatgtatacatcatggcagacaaacaaaagaatggaatcaaagttaacttcaaaattagacacaacattgaagatggaagcgttcaactagcagaccattatcaacaaaatactccaattggcgatggccctgtccttttaccagacaaccattacctgtccacacaatctgccctttcgaaagatcccaacgaaaagagagaccacatggtccttcttgagtttgtaacagctgctgggattacacatggcatggatgaactatacaaataataa");
    Sequence& terminator_seq = *new Sequence("B0012", "tcacactggctcaccttcgggtgggcctttctgcgtttata");
    Sequence& gene_seq = *new Sequence("BB0001");
    
    
    doc.add<Sequence>({&promoter_seq, &CDS_seq, &RBS_seq, &terminator_seq, &gene_seq});
    
    promoter.sequences.set(promoter_seq.identity.get());
    CDS.sequences.set(CDS_seq.identity.get());
    RBS.sequences.set(RBS_seq.identity.get());
    terminator.sequences.set(terminator_seq.identity.get());
    gene.sequences.set(gene_seq.identity.get());
    
    gene_seq.assemble();

    cout << promoter_seq.elements.get() << endl;
    cout << RBS_seq.elements.get() << endl;
    cout << CDS_seq.elements.get() << endl;
    cout << terminator_seq.elements.get() << endl;
    cout << gene_seq.elements.get() << endl;

    // Insert at the end of the primary sequence
    gene.insertDownstream(gene.components["B0012/0"], terminator);

    // Insert between two most terminal components of the primary sequence
    gene.insertDownstream(gene.components["B0012/0"], promoter);

    // Insert between two most terminal components of the primary sequence
    gene.insertUpstream(gene.components["R0010/0"], RBS);

    gene.addUpstreamFlank(gene.components["B0012/1"], "aaaaaaaa");
    gene.addDownstreamFlank(gene.components["B0012/1"], "ttttt");

//    Component& c = first;
//    cout << c.displayId.get()  << endl;
//    while (gene.hasDownstreamComponent(c))
//    {
//        c = gene.getDownstreamComponent(c);
//        cout << c.displayId.get()  << endl;
//    }
//    for (auto & sc : gene.sequenceConstraints )
//    {
//        cout << sc.displayId.get() << sc.subject.get() << sc.object.get() << endl;
//    }

    // Verify that components are in the correct order
    vector < Component* > primary_sequence = gene.getPrimaryStructure();
    for (auto & component : primary_sequence)
    {
        cout << component->displayId.get() << endl;
    }

    // Verify that an updated sequence can be calculated with the new inserts
    gene_seq.assemble();
    cout << gene_seq.elements.get() << endl;
}