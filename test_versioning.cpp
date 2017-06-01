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
    setHomespace(BASE_URI);
    toggleSBOLCompliance();

    ComponentDefinition& TargetPromoter = *new ComponentDefinition("TargetPromoter", BIOPAX_DNA, "1.0.0");
    doc.add<ComponentDefinition>(TargetPromoter);
    cout << TargetPromoter.version.get() << endl;
    cout << TargetPromoter.version.major() << endl;
    cout << TargetPromoter.version.minor() << endl;
    cout << TargetPromoter.version.patch() << endl;

    // Copy an object and automatically increment its version. If the optional version argument is specified, it will be used instead of incrementing the copied object's version. An object may also be copied into a new document and a new namespace, assuming compliant URIs.
    Document& doc2 = *new Document();

    ComponentDefinition& promoter_copy = TargetPromoter.copy<ComponentDefinition>(&doc2, "http://igem.org");
    doc2.write("copy_example.xml");
    
    
}
