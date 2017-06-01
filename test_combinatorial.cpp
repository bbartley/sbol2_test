//#define RAPTOR_STATIC

#include "sbol.h"


#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using namespace sbol;

int main()
{
    Document& doc = *new Document();
    setHomespace("http://sys-bio.org");
    ComponentDefinition& cd1 = *new ComponentDefinition("test", BIOPAX_DNA, "1-01ba\\20c");
    cout << cd1.version.get() << endl;
    pair< vector<string>, vector<string> > v = cd1.version.split();
//    for (auto i_v = v.first.begin(); i_v != v.first.end(); ++i_v)
//        cout << *i_v << endl;
//    for (auto i_v = v.second.begin(); i_v != v.second.end(); ++i_v)
//        cout << *i_v << endl;
    cd1.version.incrementMajor();
    cd1.version.incrementMinor();
    cd1.version.incrementPatch();
    cout << cd1.version.get() << endl;
    cout << cd1.identity.get() << endl;
    toggleSBOLCompliantTypes();
    ComponentDefinition& cd2 = *new ComponentDefinition("test2", BIOPAX_DNA);
    cout << cd2.identity.get() << endl;
    
//    setHomespace("http://sys-bio.org");
//    Document& doc = *new Document();
//    // Specify top-level ComponentDefinition and positional Components....
//    ComponentDefinition& top = *new ComponentDefinition("top");
//    doc.add<ComponentDefinition>(top);
//    
//    Component& pos1c = *new Component("pos1c");
//    Component& pos2c = *new Component("pos2c");
//    Component& pos3c = *new Component("pos3c");
//    top.components.add(pos1c);
//    top.components.add(pos2c);
//    top.components.add(pos3c);
//    
//    // Specify positional SequenceConstraints...
//    // pos1 - pos2 - pos3
//    SequenceConstraint& pos_sq1 = *new SequenceConstraint("pos_sq1", "pos1", "pos2", "precedes");
//    SequenceConstraint& pos_sq2 = *new SequenceConstraint("pos_sq2", "pos2", "pos1", "precedes");
//    top.sequenceConstraints.add(pos_sq1);
//    top.sequenceConstraints.add(pos_sq2);
//    
//    // SPECIFY "PARTS" #
//    
//    // Specify ComponentDefinitions....
//    ComponentDefinition& rbs1cd = *new ComponentDefinition("rbs1cd");
//    ComponentDefinition& rbs2cd = *new ComponentDefinition("rbs2cd");
//    ComponentDefinition& cds1cd = *new ComponentDefinition("cds1cd");
//    ComponentDefinition& cds2cd = *new ComponentDefinition("cds2cd");
//    doc.add<ComponentDefinition>(rbs1cd);
//    doc.add<ComponentDefinition>(rbs2cd);
//    doc.add<ComponentDefinition>(cds1cd);
//    doc.add<ComponentDefinition>(cds2cd);
//    
//    // Specify sequences...
//    Sequence& rbs1_seq = *new Sequence("rbs1cd", "aaaa");
//    Sequence& rbs2_seq = *new Sequence("rbs2cd", "cccc");
//    Sequence& cds1_seq = *new Sequence("cds1cd", "gggg");
//    Sequence& cds2_seq = *new Sequence("cds2cd", "attcga");
//    doc.add<Sequence>(rbs1_seq);
//    doc.add<Sequence>(rbs2_seq);
//    doc.add<Sequence>(cds1_seq);
//    doc.add<Sequence>(cds2_seq);
//    
//    // Associate sequences with ComponentDefinition...
//    rbs1cd.sequence.set(rbs1_seq.identity.get());
//    rbs2cd.sequence.set(rbs2_seq.identity.get());
//    cds1cd.sequence.set(cds1_seq.identity.get());
//    cds2cd.sequence.set(cds2_seq.identity.get());
//    
//    // Add components...
//    Component& rbs1c = *new Component("rbs1c");
//    Component& rbs2c = *new Component("rbs2c");
//    Component& cds1c = *new Component("cds1c");
//    Component& cds2c = *new Component("cds2c");
//    
//    top.components.add(rbs1c);
//    top.components.add(rbs2c);
//    top.components.add(cds1c);
//    top.components.add(cds2c);
//    
//    // Associate Components to ComponentDefintions...
//    //rbs1cd.components.add(rbs1c);
//    //rbs2cd.components.add(rbs2c);
//    //cds1cd.components.add(cds1c);
//    //cds2cd.components.add(cds2c);
//    rbs1c.definition.set(rbs1cd.identity.get());
//    rbs2c.definition.set(rbs2cd.identity.get());
//    cds1c.definition.set(cds1cd.identity.get());
//    cds2c.definition.set(cds2cd.identity.get());
//
//    
//    // SPECIFY COMBINATORIAL CONSTRAINTS #
//    
//    // Position 1 can be either rbs1c or rbs2...
//    SequenceConstraint& combin_pos1_1 = *new SequenceConstraint("combin_pos1_1", "pos1c", "rbs1c", SBOL_URI "#can_be");
//    SequenceConstraint& combin_pos1_2 = *new SequenceConstraint("combin_pos1_2", "pos1c", "rbs2c", SBOL_URI "#can_be");
//    top.sequenceConstraints.add(combin_pos1_1);
//    top.sequenceConstraints.add(combin_pos1_2);
//    
//    // Position 2 can be either cds1c or cds2c...
//    SequenceConstraint& combin_pos2_1 = *new SequenceConstraint("combin_pos2_1", "pos2c", "cds1c", SBOL_URI "#can_be");
//    SequenceConstraint& combin_pos2_2 = *new SequenceConstraint("combin_pos2_2", "pos2c", "cds2c", SBOL_URI "#can_be");
//    top.sequenceConstraints.add(combin_pos2_1);
//    top.sequenceConstraints.add(combin_pos2_2);
//    
//    // Position 3 can be either cds1c or cds2c...
//    SequenceConstraint& combin_pos3_1 = *new SequenceConstraint("combin_pos3_1", "pos3c", "cds1c", SBOL_URI "#can_be");
//    SequenceConstraint& combin_pos3_2 = *new SequenceConstraint("combin_pos3_2", "pos3c", "cds2c", SBOL_URI "#can_be");
//    top.sequenceConstraints.add(combin_pos3_1);
//    top.sequenceConstraints.add(combin_pos3_2);
//    
//    // But the Component at Position 2 cannot be the same as Position 3...
//    SequenceConstraint& combin_pos_not_eq =  *new SequenceConstraint("combin_pos_not_eq", "pos2c", "pos2c", SBOL_URI "#not_equal");
//    top.sequenceConstraints.add(combin_pos_not_eq);
//    
//    // Round trip...
//    doc.write("combinatorial.xml");
//    doc.read("combinatorial.xml");
//    doc.write("combinatorial_out.xml");
    
}
