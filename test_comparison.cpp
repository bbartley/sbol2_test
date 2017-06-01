#define BASE_URI "http://sys-bio.org"
#define RAPTOR_STATIC

#include "sbol.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace sbol;

int main()
{
	Document& doc = *new Document();
    Document& doc2 = *new Document();

    setHomespace(BASE_URI);

    ComponentDefinition& comparand1 = *new ComponentDefinition("TargetPromoter", BIOPAX_DNA);
    comparand1.sequenceAnnotations.create("SA");
    
    ComponentDefinition& comparand2 = *new ComponentDefinition("TargetPromoter", BIOPAX_DNA);
    comparand2.sequenceAnnotations.create("SA");

    doc.add<ComponentDefinition>(comparand1);
    doc2.add<ComponentDefinition>(comparand2);
    comparand2.sequenceAnnotations.create("SA2");

    cout << doc.compare(&doc2) << endl;    
    
}
