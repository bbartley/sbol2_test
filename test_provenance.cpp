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
    p.starttime.set("2016-03-16T");
    cout << p.starttime.get() << endl;
}
