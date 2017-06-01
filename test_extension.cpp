#include "sbol.h"

using namespace sbol;
using namespace std;

// These constants determine the appearance of nodes in the output file
#define EXTENSION_NS "http://igem.org#"   // Must end in a hash or forward-slash
#define EXTENSION_CLASS "iGEMCDef"        // Name of the class in XML output
#define EXTENSION_PREFIX "igem"           // Namespace prefix in XML output

class iGEMComponentDefinition : public ComponentDefinition  // Derive an extension class
{
    
public:
    TextProperty partStatus;
    TextProperty notes;
    TextProperty source;
    URIProperty results;
    
    // Define the constructor. Put required fields in the argument list. Each required field must have a default value specified, even if only an empty string.
    iGEMComponentDefinition(std::string uri = "", std::string partStatus = "Under construction") :
    
        // Call public base class constructor
        ComponentDefinition(uri),
    
        // Initialize member properties. The second argument must ALWAYS be 'this'.
        partStatus(EXTENSION_NS "partStatus", this, partStatus),  // The field is initialized to the value "Under construction"
        notes(EXTENSION_NS "notes", this),                        // The optional field is not initialized with any value
        source(PURL_URI "source", this),                         // Dublin Core namespace is already defined as part of the SBOL Core
        results(EXTENSION_NS "results", this)
    {
        // Register the extension class.
        register_extension_class < iGEMComponentDefinition >(EXTENSION_NS, EXTENSION_PREFIX, EXTENSION_CLASS);
    };
    
    // Destructor
    ~iGEMComponentDefinition() {};
};

class Datasheet : public TopLevel  // Derive an extension class
{
    
public:
    TextProperty transcription_rate;
    ReferencedObject part;

    
    // Define the constructor. Put required fields in the argument list. Each required field must have a default value specified, even if only an empty string.
    Datasheet(std::string uri = "") :
    
        // Call public base class constructor
        TopLevel(EXTENSION_NS "TestClass", uri),
        transcription_rate(EXTENSION_NS "transcription_rate", this),
        part(EXTENSION_NS "part", EXTENSION_NS "iGEMCDef", this)
    
    {
        // Register the extension class.
        register_extension_class < Datasheet >(EXTENSION_NS, EXTENSION_PREFIX, "Datasheet");
    };
    
    // Destructor
    ~Datasheet() {};
};

int main()
{
    Document& doc = *new Document();
	setHomespace("http://sys-bio.org");
    
    iGEMComponentDefinition& part = *new iGEMComponentDefinition("My_component", "Available");
    part.notes.set("This component works in E. coli");
    part.source.set("This component was isolated from B. subtilis");
    part.results.set("http://synbiohub.org/igem/results/Works");
    doc.add < iGEMComponentDefinition > (part);
    doc.write("igem_example.xml");

    doc.read("igem_example.xml");
    ComponentDefinition& cd = doc.componentDefinitions["My_component"];
    std::vector < std::string > properties = cd.getProperties();
    cout << cd.getPropertyValue(EXTENSION_NS "partStatus") << endl;
    cout << cd.getPropertyValue(EXTENSION_NS "notes") << endl;
    cout << cd.getPropertyValue(PURL_URI "source") << endl;
    cout << cd.getPropertyValue(EXTENSION_NS "results") << endl;

    Document& doc2 = *new Document();
    Datasheet& data = *new Datasheet("test");
    data.transcription_rate.set("0.75");
    data.part.set(part.identity.get());
    
    doc2.add <Datasheet>(data);
    doc2.write("gtl_example.xml");
}

//    Document& doc2 = *new Document();
//
//    ComponentDefinition& cd2 = cd.copy<ComponentDefinition>(&doc2, "http://igem.org", "1.0.0");
//    doc2.write("test.xml");


