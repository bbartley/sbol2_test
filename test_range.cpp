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
    doc.add<ComponentDefinition>(gene);
    
    SequenceAnnotation& sa = gene.sequenceAnnotations.create("sa");
    Range& range = sa.locations.create<Range>("range");
    range.start.set(1);
    range.end.set(10);
    doc.write("example.xml");
}
