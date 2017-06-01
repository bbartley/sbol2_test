#include "sbol.h"
#include <iostream>

using namespace sbol;
using namespace std;

int main() {
    Document& doc = *new Document();
    
    cout << "Making CRISPR bits\n";
    setHomespace("http://sys-bio.org");
    ModuleDefinition& CRPa = *new ModuleDefinition("CRISPRTemplate");
    ComponentDefinition& Cas9 = *new ComponentDefinition("Cas9", BIOPAX_PROTEIN);
    
    /******* Minimal failure model */
    doc.add<ModuleDefinition>(CRPa);
    CRPa.functionalComponents.add(Cas9);
    doc.add<ModuleDefinition>(CRPa);
    doc.add<ComponentDefinition>(Cas9);
    
    doc.write("test-sbol.xml");
    cout << "Should have failed already" << endl;
}