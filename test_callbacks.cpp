#include "sbol.h"
#include <iostream>

using namespace sbol;
using namespace std;

void get_sequence_annotation_callback(ComponentDefinition* cdef_node, void * user_data)
{
    cout << "Getting " << cdef_node->sequenceAnnotations.size() << endl;
    vector<SequenceAnnotation*> annotations = cdef_node->sequenceAnnotations.getObjects();

    if (annotations.size() > 0)
    {
        vector<SequenceAnnotation*>& cumulative_annotations = (vector<SequenceAnnotation*>&)*user_data;
        cumulative_annotations.reserve(cumulative_annotations.size() + distance(annotations.begin(), annotations.end()));
        cumulative_annotations.insert(cumulative_annotations.end(), annotations.begin(), annotations.end());
    }
};

int main() {
    Document& doc = *new Document();
    
    setHomespace("http://sys-bio.org");
    ComponentDefinition& genome = *new ComponentDefinition("genome");
    ComponentDefinition& operon = *new ComponentDefinition("operon");
    ComponentDefinition& gene = *new ComponentDefinition("gene");
    Component& c_operon = genome.components.create("operon");
    c_operon.definition.set(operon.identity.get());
    Component& c_gene = operon.components.create("gene");
    c_gene.definition.set(gene.identity.get());
    doc.add<ComponentDefinition>({ &genome, &operon, &gene });
    
    SequenceAnnotation& sa1 = gene.sequenceAnnotations.create("sa1");
    SequenceAnnotation& sa2 = gene.sequenceAnnotations.create("sa2");
    SequenceAnnotation& sa3 = gene.sequenceAnnotations.create("sa3");

    sa1.roles.set("test");
    sa2.roles.set("test");
    sa3.roles.set("test");

    vector<SequenceAnnotation*> annotations;
    vector<ComponentDefinition*> cdefs = genome.applyToComponentHierarchy(get_sequence_annotation_callback, &annotations);
    cout << annotations.size() << endl;
    for (auto &ann : annotations)
        cout << ann->roles.get() << endl;
}