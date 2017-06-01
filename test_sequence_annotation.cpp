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

    ComponentDefinition& biobrick_prefix = *new ComponentDefinition("biobrick_prefix", BIOPAX_DNA);
    SequenceAnnotation& ecori = biobrick_prefix.sequenceAnnotations.create("EcoRI");
    ecori.roles.set(SO "0001975");  // five prime sticky end restriction enzyme cleavage site
    
    Range& range = ecori.locations.create<Range>("range");
    range.orientation.set(SBOL_ORIENTATION_INLINE);
    range.start.set(1);
    range.end.set(7);
    
    Cut& cut = ecori.locations.create<Cut>("cut");
    cut.at.set(4);
    
    SequenceAnnotation& noti = biobrick_prefix.sequenceAnnotations.create("NotI");
    noti.roles.set(SO "0001975");  // five prime sticky end restriction enzyme cleavage site
    
    SequenceAnnotation& xbai = biobrick_prefix.sequenceAnnotations.create("XbaI");
    xbai.roles.set(SO "0001975");  // five prime sticky end restriction enzyme cleavage site


    
}
