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

    ComponentDefinition& cdef = *new ComponentDefinition("TargetPromoter", BIOPAX_DNA);
    cout << cdef.roles.size() << endl;

    cdef.roles.set(SO_MISC);
    cdef.roles.add(SO_PROMOTER);
    cdef.roles.add(SO_RBS);
    cout << cdef.roles.size() << endl;
    cdef.roles.remove(2);
    cout << cdef.roles.size() << endl;
    cdef.roles.clear();
    cout << cdef.roles.size() << endl;

    SequenceAnnotation& SA = cdef.sequenceAnnotations.create("SA");
    SequenceAnnotation& SA2 = cdef.sequenceAnnotations.create("SA2");
    SequenceAnnotation& SA3 = cdef.sequenceAnnotations.create("SA3");
    cout << cdef.sequenceAnnotations.size() << endl;
    cdef.sequenceAnnotations.remove(SA3.identity.get());
    cout << cdef.sequenceAnnotations.size() << endl;
    cdef.sequenceAnnotations.remove();
    cout << cdef.sequenceAnnotations.size() << endl;

    cdef.sequenceAnnotations.clear();
    cout << cdef.sequenceAnnotations.size() << endl;

}
