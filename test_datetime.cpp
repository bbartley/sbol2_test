#include "sbol.h"
#include <iostream>

using namespace sbol;
using namespace std;

class Provenance : public SBOLObject
{
public:
    DateTimeProperty starttime;
    
    Provenance(std::string uri) :
        SBOLObject(SBOL_URI "#Provenance", uri),
        starttime(SBOL_URI "#starttime", this, "2016-03-16T")
    {};

};

int main() {
    Document& doc = *new Document();
    setHomespace("http://sys-bio.org");
    Provenance& p = *new Provenance("test");
    
    p.starttime.set("2002-09-24Z");  // Z indicates timezone
    cout << p.starttime.get() << endl;
    
    p.starttime.set("2002-09-24T20:12:00"); // T indicates Time data type follows Date
    cout << p.starttime.get() << endl;
    
    p.starttime.set("2002-09-24T20:12:00.5");  // Decimal
    cout << p.starttime.get() << endl;
    
    p.starttime.set("2002-09-24T20:12:00Z");  // Time zone
    cout << p.starttime.get() << endl;
    
    p.starttime.set("2002-09-24T20:12:00.5+06:00");  // Positive offset
    cout << p.starttime.get() << endl;

    p.starttime.set("2002-09-24T20:12:00.5-06:00");  // Negative offset
    cout << p.starttime.get() << endl;
    
    try
    {
        p.starttime.set("2002-09-2");  // Fail
    }
    catch(...)
    {
        cout << "2002-09-2 FAILED" << endl;
    }
}
