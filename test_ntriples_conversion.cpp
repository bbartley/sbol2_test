#include "sbol.h"
#include <iostream>

using namespace sbol;
using namespace std;

void test_escape_code(string f, string s)
{
    Document& doc = *new Document();
    ComponentDefinition& cdef = *new ComponentDefinition("http://www.examples.org/cdef");
    cdef.description.set(s);
    doc.write(f);
    doc.read(f);
    cout << "Testing " << f << endl;
    cout << cdef.description.get() << endl;
    cout << convert_ntriples_encoding_to_ascii(cdef.description.get()) << endl;
    cout << "==========" << endl;
    doc.close();
}

int main()
{
    test_escape_code("escape_code_example_0.xml", "token1\\\\token2");
    test_escape_code("escape_code_example_1.xml", "token1\\\"token2\\\"token3");
    test_escape_code("escape_code_example_2.xml", "token1\rtoken2");
    test_escape_code("escape_code_example_3.xml", "token1\ntoken2");
    test_escape_code("escape_code_example_4.xml", "token1   token2");


}