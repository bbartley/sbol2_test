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



#define SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE SO "0001975"
#define SO_THREE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE SO "0001976"

#include "sbol.h"


#include <iostream>
#include <vector>

using namespace std;
using namespace sbol;

int main()
{
	cout << "Test";
    setHomespace(BASE_URI);
    Document& doc = *new Document();

	// A ComponentDefinition's molecular type is indicated by an ontology term from
	// BioPax
	ComponentDefinition& dna = *new ComponentDefinition("dna", BIOPAX_DNA);
	ComponentDefinition& rna = *new ComponentDefinition("rna", BIOPAX_RNA);
	ComponentDefinition& protein = *new ComponentDefinition("protein", BIOPAX_PROTEIN);
	
	// If no term is specified, then by default a DNA component is created
    ComponentDefinition& promoter = *new ComponentDefinition("R0010");
    ComponentDefinition& RBS = *new ComponentDefinition("B0032");
    ComponentDefinition& CDS = *new ComponentDefinition("E0040");
    ComponentDefinition& terminator = *new ComponentDefinition("B0012");
	ComponentDefinition& vector_backbone = *new ComponentDefinition("pSB1A2");

	doc.add<ComponentDefinition>(promoter);
	doc.add<ComponentDefinition>({ &CDS, &RBS, &terminator, &vector_backbone });

	// The function of a genetic part/component is specified in its roles property
	// A Sequence Ontology term is used to specify the role
	// A few common terms are represented with built-in constants
	// Browse terms at http://www.sequenceontology.org/browser/obob.cgi
    promoter.roles.set(SO_PROMOTER);
    CDS.roles.set(SO_CDS);
    RBS.roles.set(SO_RBS);
    terminator.roles.set(SO_TERMINATOR);
	vector_backbone.roles.set(SO_PLASMID);

	SequenceAnnotation& speI = vector_backbone.sequenceAnnotations.create("SpeI");
	speI.roles.set(SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r1 = speI.locations.create<Range>("r1");
	r1.start.set(2);
	r1.end.set(7);

	SequenceAnnotation& notI_1 = vector_backbone.sequenceAnnotations.create("NotI_2");
	notI_1.roles.set(SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r2 = notI_1.locations.create<Range>("r2");
	r2.start.set(9);
	r2.end.set(17);

	SequenceAnnotation& pstI = vector_backbone.sequenceAnnotations.create("PstI");
	pstI.roles.set(SO_THREE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r3 = pstI.locations.create<Range>("r3");
	r3.start.set(18);
	r3.end.set(24);
	
	SequenceAnnotation& ecoRI = vector_backbone.sequenceAnnotations.create("EcoRI");
	ecoRI.roles.set(SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r4 = ecoRI.locations.create<Range>("r4");
	r4.start.set(2058);
	r4.end.set(2063);

	SequenceAnnotation& notI_2 = vector_backbone.sequenceAnnotations.create("NotI_1");
	notI_2.roles.set(SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r5 = notI_2.locations.create<Range>("r5");
	r5.start.set(2064);
	r5.end.set(2072);

	SequenceAnnotation& xbaI = vector_backbone.sequenceAnnotations.create("XbaI");
	xbaI.roles.set(SO_FIVE_PRIME_STICKY_END_RESTRICTION_ENZYME_CLEAVAGE_SITE);
	Range& r6 = xbaI.locations.create<Range>("r6");
	r6.start.set(2074);
	r6.end.set(2080);
    
	ComponentDefinition& plasmid = *new ComponentDefinition("BB0001");
	
	// Per section 7.7 of the spec, topological features are indicated in the types field (rather than roles)
	plasmid.types.add(SO_CIRCULAR);
	plasmid.types.add(SO "0000985");  // Sequence Ontology term for double-stranded DNA
	vector<ComponentDefinition*> primary_structure = { &vector_backbone, &promoter, &RBS, &CDS, &terminator };
	plasmid.assemblePrimaryStructure(primary_structure, IGEM_STANDARD_ASSEMBLY);

	
    Component& first = vector_backbone.getFirstComponent();
    cout << first.identity.get() << endl;
    Component& last = vector_backbone.getLastComponent();
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
    Sequence& vector_backbone_seq = *new Sequence("BB0001", "tactagtagcggccgctgcaggcttcctcgctcactgactcgctgcgctcggtcgttcggctgcggcgagcggtatcagctcactcaaaggcggtaatacggttatccacagaatcaggggataacgcaggaaagaacatgtgagcaaaaggccagcaaaaggccaggaaccgtaaaaaggccgcgttgctggcgtttttccataggctccgcccccctgacgagcatcacaaaaatcgacgctcaagtcagaggtggcgaaacccgacaggactataaagataccaggcgtttccccctggaagctccctcgtgcgctctcctgttccgaccctgccgcttaccggatacctgtccgcctttctcccttcgggaagcgtggcgctttctcatagctcacgctgtaggtatctcagttcggtgtaggtcgttcgctccaagctgggctgtgtgcacgaaccccccgttcagcccgaccgctgcgccttatccggtaactatcgtcttgagtccaacccggtaagacacgacttatcgccactggcagcagccactggtaacaggattagcagagcgaggtatgtaggcggtgctacagagttcttgaagtggtggcctaactacggctacactagaaggacagtatttggtatctgcgctctgctgaagccagttaccttcggaaaaagagttggtagctcttgatccggcaaacaaaccaccgctggtagcggtggtttttttgtttgcaagcagcagattacgcgcagaaaaaaaggatctcaagaagatcctttgatcttttctacggggtctgacgctcagtggaacgaaaactcacgttaagggattttggtcatgagattatcaaaaaggatcttcacctagatccttttaaattaaaaatgaagttttaaatcaatctaaagtatatatgagtaaacttggtctgacagttaccaatgcttaatcagtgaggcacctatctcagcgatctgtctatttcgttcatccatagttgcctgactccccgtcgtgtagataactacgatacgggagggcttaccatctggccccagtgctgcaatgataccgcgagacccacgctcaccggctccagatttatcagcaataaaccagccagccggaagggccgagcgcagaagtggtcctgcaactttatccgcctccatccagtctattaattgttgccgggaagctagagtaagtagttcgccagttaatagtttgcgcaacgttgttgccattgctacaggcatcgtggtgtcacgctcgtcgtttggtatggcttcattcagctccggttcccaacgatcaaggcgagttacatgatcccccatgttgtgcaaaaaagcggttagctccttcggtcctccgatcgttgtcagaagtaagttggccgcagtgttatcactcatggttatggcagcactgcataattctcttactgtcatgccatccgtaagatgcttttctgtgactggtgagtactcaaccaagtcattctgagaatagtgtatgcggcgaccgagttgctcttgcccggcgtcaatacgggataataccgcgccacatagcagaactttaaaagtgctcatcattggaaaacgttcttcggggcgaaaactctcaaggatcttaccgctgttgagatccagttcgatgtaacccactcgtgcacccaactgatcttcagcatcttttactttcaccagcgtttctgggtgagcaaaaacaggaaggcaaaatgccgcaaaaaagggaataagggcgacacggaaatgttgaatactcatactcttcctttttcaatattattgaagcatttatcagggttattgtctcatgagcggatacatatttgaatgtatttagaaaaataaacaaataggggttccgcgcacatttccccgaaaagtgccacctgacgtctaagaaaccattattatcatgacattaacctataaaaataggcgtatcacgaggcagaatttcagataaaaaaaatccttagctttcgctaaggatgatttctggaattcgcggccgcttctagag");

//    doc.add<Sequence>({&promoter_seq, &CDS_seq, &RBS_seq, &terminator_seq, &gene_seq});
    
    promoter.sequence.set(promoter_seq);
    CDS.sequence.set(CDS_seq);
    RBS.sequence.set(RBS_seq);
    terminator.sequence.set(terminator_seq);
	vector_backbone.sequence.set(vector_backbone_seq);
    
    plasmid.compile();

}