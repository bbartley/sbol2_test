#include "sbol.h"
#include <iostream>

using namespace sbol;
using namespace std;

int main() {
    Document& doc = *new Document();
    
    setHomespace("http://sys-bio.org");
    ModuleDefinition& CRPa = *new ModuleDefinition("CRISPRTemplate");
    ComponentDefinition& Cas9 = *new ComponentDefinition("Cas9", BIOPAX_DNA);
    doc.add<ModuleDefinition>(CRPa);
    doc.add<ComponentDefinition>(Cas9);
    
    string results = doc.validate();
    if (results.compare("") == 0)
        cout << "Valid" << endl;
    cout << results.length() << endl;
    cout << results << endl;
    Cas9.types.set("");
    results = doc.validate();
    cout << results << endl;
}