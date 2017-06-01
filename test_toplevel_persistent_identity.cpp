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

    ComponentDefinition& cd = *new ComponentDefinition("CRISPR_Example/CRP_b");
    Sequence& seq = *new Sequence("CRISPR_Example/CRP_b_seq");
    doc.add<ComponentDefinition>(cd);
    doc.add<Sequence>(seq);
    
    try
    {
        ComponentDefinition& cd0 = doc.get<ComponentDefinition>("CRP_b");
        if (cd0.identity.get().compare(cd.identity.get()) == 0)
            cout << "=== PASSED ===" << endl;
        else
        {
            cout << cd0.identity.get() << endl;
            throw SBOLError(SBOL_ERROR_INVALID_ARGUMENT, "");
        }
    }
    catch(SBOLError& e)
    {
        cout << "=== FAILED ===" << endl;
    }
    try
    {
        ComponentDefinition& cd0 = doc.get<ComponentDefinition>("CRISPR_Example/CRP_b");
        if (cd0.identity.get().compare(cd.identity.get()) == 0)
            cout << "=== PASSED ===" << endl;
        else
        {
            cout << cd0.identity.get() << endl;
            throw SBOLError(SBOL_ERROR_INVALID_ARGUMENT, "");
        }
    }
    catch(SBOLError& e)
    {
        cout << "=== FAILED ===" << endl;
    }
    try
    {
        ComponentDefinition& cd0 = doc.get<ComponentDefinition>(BASE_URI "/CRISPR_Example/CRP_b");
        if (cd0.identity.get().compare(cd.identity.get()) == 0)
            cout << "=== PASSED ===" << endl;
        else
        {
            cout << cd0.identity.get() << endl;
            throw SBOLError(SBOL_ERROR_INVALID_ARGUMENT, "");
        }
    }
    catch(SBOLError& e)
    {
        cout << "=== FAILED ===" << endl;
    }
    
    try
    {
        ComponentDefinition& cd0 = doc.get<ComponentDefinition>(BASE_URI "/ComponentDefinition/CRISPR_Example/CRP_b");
        if (cd0.identity.get().compare(cd.identity.get()) == 0)
            cout << "=== PASSED ===" << endl;
        else
        {
            cout << cd0.identity.get() << endl;
            throw SBOLError(SBOL_ERROR_INVALID_ARGUMENT, "");
        }
    }
    catch(SBOLError& e)
    {
        cout << "=== FAILED ===" << endl;
    }
    
    try
    {
        ComponentDefinition& cd0 = doc.get<ComponentDefinition>(BASE_URI "/ComponentDefinition/CRISPR_Example/CRP_b/1.0.0");
        if (cd0.identity.get().compare(cd.identity.get()) == 0)
            cout << "=== PASSED ===" << endl;
        else
        {
            cout << cd0.identity.get() << endl;
            throw SBOLError(SBOL_ERROR_INVALID_ARGUMENT, "");
        }
    }
    catch(SBOLError& e)
    {
        cout << "=== FAILED ===" << endl;
    }
}
