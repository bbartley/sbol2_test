// Final Testing of LibSBOL.cpp : main project file.

#include "sbol.h"
#include <vector>
#include <string>
using namespace sbol;

std::vector<std::string> get_files()
{
	std::vector<std::string> SBOL2Files;

	SBOL2Files.push_back("AnnotationOutput.rdf");
	SBOL2Files.push_back("BBa_I0462.rdf");
//	SBOL2Files.push_back("BBa_I0462_orig.rdf");
	SBOL2Files.push_back("CollectionOutput.rdf");
	SBOL2Files.push_back("ComponentDefinitionOutput.rdf");

	SBOL2Files.push_back("CreateAndRemoveCollections.rdf");
	SBOL2Files.push_back("CreateAndRemoveComponentDefinition.rdf");
	SBOL2Files.push_back("CreateAndRemoveGenericTopLevel.rdf");
	SBOL2Files.push_back("CreateAndRemoveModel.rdf");
	SBOL2Files.push_back("CreateAndRemoveModuleDefinition.rdf");

	SBOL2Files.push_back("CutExample.rdf");
	SBOL2Files.push_back("GenericTopLevelOutput.rdf");
	SBOL2Files.push_back("igem1.rdf");
	SBOL2Files.push_back("igem2.rdf");
	SBOL2Files.push_back("igem3.rdf");

	SBOL2Files.push_back("labhost_All.rdf");
//	SBOL2Files.push_back("labhost_All_orig.rdf");
	SBOL2Files.push_back("labhost_Aspergillus_nidulans.rdf");
//	SBOL2Files.push_back("labhost_Aspergillus_nidulans_orig.rdf");
	SBOL2Files.push_back("labhost_Bacillus_subtilis.rdf");

//	SBOL2Files.push_back("labhost_Bacillus_subtilis_orig.rdf");
	SBOL2Files.push_back("labhost_Drosophila_melanogaster.rdf");
//	SBOL2Files.push_back("labhost_Drosophila_melanogaster_orig.rdf");
	SBOL2Files.push_back("labhost_Escherichia_Coli.rdf");
//	SBOL2Files.push_back("labhost_Escherichia_Coli_orig.rdf");

	SBOL2Files.push_back("labhost_Gram-negative_bacteria.rdf");
//	SBOL2Files.push_back("labhost_Gram-negative_bacteria_orig.rdf");
	SBOL2Files.push_back("labhost_Insect_Cells.rdf");
//	SBOL2Files.push_back("labhost_Insect_Cells_orig.rdf");
	SBOL2Files.push_back("labhost_Kluyveromyces_lactis.rdf");

//	SBOL2Files.push_back("labhost_Kluyveromyces_lactis_orig.rdf");
	SBOL2Files.push_back("labhost_Mammalian_Cells.rdf");
//	SBOL2Files.push_back("labhost_Mammalian_Cells_orig.rdf");
	SBOL2Files.push_back("labhost_Pichia_pastoris.rdf");
//	SBOL2Files.push_back("labhost_Pichia_pastoris_orig.rdf");

	SBOL2Files.push_back("labhost_Plant_Cells.rdf");
//	SBOL2Files.push_back("labhost_Plant_Cells_orig.rdf");
	SBOL2Files.push_back("labhost_Saccharomyces_cerevisiae.rdf");
//	SBOL2Files.push_back("labhost_Saccharomyces_cerevisiae_orig.rdf");
	SBOL2Files.push_back("labhost_Schizosaccharomyces_pombe.rdf");

//	SBOL2Files.push_back("labhost_Schizosaccharomyces_pombe_orig.rdf");
	SBOL2Files.push_back("labhost_Unspecified.rdf");
//	SBOL2Files.push_back("labhost_Unspecified_orig.rdf");
	SBOL2Files.push_back("memberAnnotations.rdf");
	SBOL2Files.push_back("ModelOutput.rdf");

	SBOL2Files.push_back("ModuleDefinitionOutput.rdf"); 
	SBOL2Files.push_back("multipleCollections_no_Members.rdf");
	SBOL2Files.push_back("multipleGenericTopLevel.rdf");
	SBOL2Files.push_back("multipleSequences.rdf");
	SBOL2Files.push_back("namespace.rdf");

	SBOL2Files.push_back("partial_pIKE_left_cassette.rdf"); 
//	SBOL2Files.push_back("partial_pIKE_left_cassette_orig.rdf"); 
	SBOL2Files.push_back("partial_pIKE_right_cassette.rdf");
//	SBOL2Files.push_back("partial_pIKE_right_cassette_orig.rdf"); 
	SBOL2Files.push_back("partial_pTAK_left_cassette.rdf");

//	SBOL2Files.push_back("partial_pTAK_left_cassette_orig.rdf"); 
	SBOL2Files.push_back("partial_pTAK_right_cassette.rdf");
//	SBOL2Files.push_back("partial_pTAK_right_cassette_orig.rdf");
	SBOL2Files.push_back("pIKE_pTAK_cassettes 2.rdf");
//	SBOL2Files.push_back("pIKE_pTAK_cassettes 2_orig.rdf");

	SBOL2Files.push_back("pIKE_pTAK_cassettes.rdf");
//	SBOL2Files.push_back("pIKE_pTAK_cassettes_orig.rdf");
	SBOL2Files.push_back("pIKE_pTAK_left_right_cassettes.rdf");
//	SBOL2Files.push_back("pIKE_pTAK_left_right_cassettes_orig.rdf");
	SBOL2Files.push_back("pIKE_pTAK_toggle_switches.rdf");

//	SBOL2Files.push_back("pIKE_pTAK_toggle_switches_orig.rdf");
	SBOL2Files.push_back("RepressionModel.rdf");
	SBOL2Files.push_back("sampleToggleSwitch.rdf");
//	SBOL2Files.push_back("SBOL1and2Test.rdf");
	SBOL2Files.push_back("SBOLDocumentOutput.rdf");

	SBOL2Files.push_back("sequence1.rdf");
	SBOL2Files.push_back("sequence2.rdf");
	SBOL2Files.push_back("sequence3.rdf");
	SBOL2Files.push_back("sequence4.rdf");
	SBOL2Files.push_back("SequenceConstraintOutput.rdf");

	SBOL2Files.push_back("SequenceOutput.rdf");
	SBOL2Files.push_back("SimpleComponentDefinitionExample.rdf");
	SBOL2Files.push_back("SimpleModuleDefinition.rdf");
	SBOL2Files.push_back("singleCollection.rdf");
	SBOL2Files.push_back("singleCompDef_withSeq.rdf");

	SBOL2Files.push_back("singleComponentDefinition.rdf");
	SBOL2Files.push_back("singleFunctionalComponent.rdf");
	SBOL2Files.push_back("singleGenericTopLevel.rdf");
	SBOL2Files.push_back("singleModel.rdf");
	SBOL2Files.push_back("singleModuleDefinition.rdf");

	SBOL2Files.push_back("singleSequence.rdf");
	SBOL2Files.push_back("test_Collection_remove.rdf");
	SBOL2Files.push_back("test_ComponentDefinition_remove.rdf");
	SBOL2Files.push_back("test_GenericTopLevel_remove.rdf");
	SBOL2Files.push_back("test_Methods.rdf");

	SBOL2Files.push_back("test_Model_remove.rdf");
	SBOL2Files.push_back("test_ModuleDefinition_remove.rdf");
	SBOL2Files.push_back("test_Sequence_remove.rdf");
	SBOL2Files.push_back("toggle.rdf");

	return SBOL2Files;
}

int main()
{
	//create an SBOL Document to read into
	setHomespace("http://sys-bio.org");
	Document &doc = *new Document();
    Document &doc2 = *new Document();
	std::string version = "1.0.0";
    
	//get SBOL2 files
	std::vector<std::string> SBOL2Files = get_files();
//    std::vector<std::string> SBOL2Files;
//    SBOL2Files.push_back("GenericTopLevelOutput.rdf");
//    SBOL2Files.push_back("AnnotationOutput.rdf");

    //read every test file from SBOL2 directory
	for (int i = 0; i < SBOL2Files.size(); ++i)
	{
		std::string path = "SBOL2/";
		std::string filename = SBOL2Files.at(i);

        std::cout << "Testing " << filename << std::endl;
		doc.read(path + filename);
        std::cout << "Writing " << filename << std::endl;
		doc.write(std::string("new_") + filename);
        std::cout << "Reading " << filename << std::endl;
        doc2.read(std::string("new_") + filename);
        int is_equal_to = doc.compare(&doc2);
        std::cout << "Namespaces : " << doc.getNamespaces().size() << "\t" << doc2.getNamespaces().size() << std::endl;
        if (is_equal_to)
            std::cout << "=== " << filename << " passed ===" << std::endl;
        else
            std::cout << "XXX " << filename << " failed XXX" << std::endl;
    }

    return 0;
}


