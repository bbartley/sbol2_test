#define RAPTOR_STATIC
#define BASE_URI "http://sys-bio.org"

#include "sbol.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <raptor2.h>

using namespace std;
using namespace sbol;

#pragma message "XMLPUBVAR = " QUOTE(XMLPUBVAR)
#pragma message "__MINGW32__ = " QUOTE(__MINGW32__)
#pragma message "_WIN32 = " QUOTE(_WIN32)
#pragma message "LIBXML_STATIC = " QUOTE(LIBXML_STATIC)

int main()
{
	Document& doc = Document();
	return 0;
}
