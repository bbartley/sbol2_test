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
    toggleSBOLCompliance();
    cout << getHomespace() << isSBOLCompliant() << endl;
    string v = "1.0.0";

    ComponentDefinition& TargetPromoter = *new ComponentDefinition("TargetPromoter", BIOPAX_DNA, "1.0.0");
    cout << TargetPromoter.displayId.get() << endl;
    cout << TargetPromoter.identity.get() << endl;
    cout << TargetPromoter.version.get() << endl;
    cout << TargetPromoter.version.major() << endl;

    ComponentDefinition& CDS = *new ComponentDefinition("CDS", BIOPAX_DNA, "1.0.0");
    ComponentDefinition& root = *new ComponentDefinition("design", BIOPAX_DNA, "1.0.0");
    //vector<ComponentDefinition*> subcomponents = { &TargetPromoter, &CDS };
    join(root, { &TargetPromoter, &CDS });
    //doc.add<ComponentDefinition>(root);
    doc.add<ComponentDefinition>(CDS);
    doc.add<ComponentDefinition>(TargetPromoter);
    doc.add<ComponentDefinition>(root);
    doc.write("hierarchy.xml");

    //doc.add<ComponentDefinition>(TargetPromoter);
    //doc.write("test.xml");
    
//	// Here we use CamelCase for displayID's, to distinguish Definitions from instances
//    ModuleDefinition& CRISPRTemplate = *new ModuleDefinition(BASE_URI, "CRISPRTemplate", v);
//    ModuleDefinition& CRPbCircuit = *new ModuleDefinition(BASE_URI, "CRPbCircuit", v);
//
//    // Components in the CRISPR Template
//    ComponentDefinition& Cas9 = *new ComponentDefinition(BASE_URI, "Cas9", v, BIOPAX_PROTEIN);
//    ComponentDefinition& GuideRNA = *new ComponentDefinition(BASE_URI, "GuideRNA", v, BIOPAX_RNA);
//	ComponentDefinition& Cas9GuideRNAComplex = *new ComponentDefinition(BASE_URI, "Cas9-GuideRNAComplex", v, BIOPAX_COMPLEX);
//	ComponentDefinition& TargetPromoter = *new ComponentDefinition(BASE_URI, "TargetPromoter", v, BIOPAX_DNA);
//    ComponentDefinition& TargetGene = *new ComponentDefinition(BASE_URI, "TargetGene", v, BIOPAX_DNA);
//    ComponentDefinition& TargetProtein = *new ComponentDefinition(BASE_URI, "TargetProtein", v, BIOPAX_PROTEIN);
//
//    
//    // Start the CRPb Characterization Module
//    // For simplicity, only components that interface with the CRISPRTemplate Module are defined here.  For now, the rest of the module is treated like a black box
//    // Components in the CRPb Characterization Module
//    ComponentDefinition& Cas9mBFP = *new ComponentDefinition(BASE_URI, "Cas9-mBFP", v, BIOPAX_PROTEIN);  // This is an output of the Module
//    ComponentDefinition& GuideRNAb = *new ComponentDefinition(BASE_URI, "GuideRNAb", v, BIOPAX_RNA);  // This is an output of the Module
//    ComponentDefinition& Cas9mBFPGuideRNAComplex = *new ComponentDefinition(BASE_URI, "Cas9mBFPGuideRNAComplex", v, BIOPAX_RNA);
//    ComponentDefinition& CRPbPromoter = *new ComponentDefinition(BASE_URI, "CRPbPromoter", v, BIOPAX_DNA);
//    ComponentDefinition& EYFPGene = *new ComponentDefinition(BASE_URI, "EYFPGene", v, BIOPAX_DNA);
//    ComponentDefinition& EYFP = *new ComponentDefinition(BASE_URI, "EYFP", v, BIOPAX_PROTEIN);  // This is the input of the Module
//    
//    doc.add<ModuleDefinition>(CRISPRTemplate);
//    doc.add<ComponentDefinition>(Cas9);
//    doc.add<ComponentDefinition>(GuideRNA);
//    doc.add<ComponentDefinition>(Cas9GuideRNAComplex);
//    doc.add<ComponentDefinition>(TargetPromoter);
//    doc.add<ComponentDefinition>(TargetGene);
//    doc.add<ComponentDefinition>(TargetProtein);
// 
//    doc.add<ModuleDefinition>(CRPbCircuit);
//    doc.add<ComponentDefinition>(Cas9mBFP);
//    doc.add<ComponentDefinition>(GuideRNAb);
//    doc.add<ComponentDefinition>(Cas9mBFPGuideRNAComplex);
//    doc.add<ComponentDefinition>(CRPbPromoter);
//    doc.add<ComponentDefinition>(EYFPGene);
//    doc.add<ComponentDefinition>(EYFP);
//    
//    // Instantiate Modules
//    Module& crispr_template = *new Module(BASE_URI, "crispr_template", v, "sys-bio.org/ModuleDefinition/CRISPRTemplate/1.0.0");
//    Module& crpb_circuit = *new Module(BASE_URI, "crpb_circuit", v, "sys-bio.org/ModuleDefinition/CRPbPromoter/1.0.0");
//    CRPbCircuit.modules.add(crpb_circuit);
//
//    // Define the Components at the interface of the two Modules
//    FunctionalComponent& cas9 = *new FunctionalComponent(BASE_URI, "cas9", v, "sys-bio.org/ComponentDefinition/Cas9/1.0.0", SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_IN);
//    FunctionalComponent& guide_rna = *new FunctionalComponent(BASE_URI, "guide_rna", v, GuideRNA.identity.get(), SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_IN);
//    FunctionalComponent& target_protein = *new FunctionalComponent(BASE_URI, "target_protein", v, TargetProtein.identity.get(), SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_OUT);
//
//    FunctionalComponent& cas9_mbfp = *new FunctionalComponent(BASE_URI, "cas9_mbfp", v, Cas9mBFP.identity.get(), SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_OUT);
//    FunctionalComponent& guide_rna_b = *new FunctionalComponent(BASE_URI, "guide_rna_b", v, GuideRNAb.identity.get(), SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_OUT);
//    FunctionalComponent& eyfp = *new FunctionalComponent(BASE_URI, "eyfp", v, EYFP.identity.get(), SBOL_ACCESS_PUBLIC, SBOL_DIRECTION_OUT);
//
//    // Connect the modules
//    MapsTo& cas9_input = *new MapsTo(BASE_URI, "cas9_input", v, cas9.identity.get(), cas9_mbfp.identity.get(), SBOL_REFINEMENT_USE_REMOTE);
//    MapsTo& guide_rna_input = *new MapsTo(BASE_URI, "guide_rna_input", v, guide_rna.identity.get(), guide_rna_b.identity.get(), SBOL_REFINEMENT_USE_REMOTE);
//    MapsTo& eyfp_output = *new MapsTo(BASE_URI, "eyfp_output", v, target_protein.identity.get(), eyfp.identity.get(), SBOL_REFINEMENT_USE_REMOTE);
//
//    crispr_template.mapsTos.add(cas9_input);
//    crispr_template.mapsTos.add(guide_rna_input);
//    crispr_template.mapsTos.add(eyfp_output);
//    
//    // The crispr_template and crpb_circuit modules are now connected!  Note that the modules are essentially black boxes at this point -- we haven't described their internal workings yet!
//    
//    // Define the inner workings of the CRISPR_Template ModuleDefinition.  The Module contains two interactions, one for complex formation and the other for gene expression.
//    // We'll start with complex formation...
//    Interaction& Cas9ComplexFormation = *new Interaction(BASE_URI, "complex_formation", v, SBO_NONCOVALENT_BINDING);
//    Interaction& CRISPRRepression = *new Interaction(BASE_URI, "gene_inhibition", v, SBO_INHIBITION);
//    Interaction& TargetProduction = *new Interaction(BASE_URI, "target_production", v, SBO_GENETIC_PRODUCTION);
//
//    CRISPRTemplate.interactions.add(Cas9ComplexFormation);
//    CRISPRTemplate.interactions.add(CRISPRRepression);
//    CRISPRTemplate.interactions.add(TargetProduction);
//
//    // Here we represent complex formation as the reaction A + B = AB
//	Participation& A = *new Participation(BASE_URI, "A", v, "sys-bio.org/FunctionalComponent/cas9/1.0.0");
//	Participation& B = *new Participation(BASE_URI, "B", v, "sys-bio.org/FunctionalComponent/guide_rna/1.0.0");
//	Participation& AB = *new Participation(BASE_URI, "AB", v, "sys-bio.org/FunctionalComponent/cas9-guide_rna_complex/1.0.0"); // Note that this FunctionalComponent hasn't been created yet!
//    A.roles.set( SBO_REACTANT );
//    B.roles.set( SBO_REACTANT );
//    AB.roles.set( SBO_PRODUCT );
//    
//    Cas9ComplexFormation.participations.add(A);
//	Cas9ComplexFormation.participations.add(B);
//	Cas9ComplexFormation.participations.add(AB);
//
//    // Here we define gene expression
//    FunctionalComponent& target_promoter = *new FunctionalComponent(BASE_URI, "target_promoter", v, TargetPromoter.identity.get(), SBOL_ACCESS_PRIVATE, SBOL_DIRECTION_NONE);
//    FunctionalComponent& cas9_grna_complex = *new FunctionalComponent(BASE_URI, "cas9_grna_complex", v, Cas9GuideRNAComplex.identity.get(), SBOL_ACCESS_PRIVATE, SBOL_DIRECTION_NONE );
//    
//	TargetProduction.participations.create(BASE_URI, "TargetProduction/promoter", v);  // The create method is general and not specialized for every class like libSBOLj's.
//    TargetProduction.participations.create(BASE_URI, "TargetProduction/gene", v);
//    TargetProduction.participations.create(BASE_URI, "TargetProduction/gene_product", v);
//    
//    // Child objects (corresponding to black diamonds in UML) can be accessed by uri
//    TargetProduction.participations[ "sys-bio.org/Participation/TargetProduction/promoter/1.0.0" ].roles.set(SBO_PROMOTER);
//    TargetProduction.participations[ "sys-bio.org/Participation/TargetProduction/gene/1.0.0" ].roles.set(SBO_PROMOTER);
//    TargetProduction.participations[ "sys-bio.org/Participation/TargetProduction/gene_product/1.0.0" ].roles.set(SBO_PRODUCT);
//
//    // Child objects can be dereferenced by numerical index, too.
//    TargetProduction.participations[ 0 ].participant.setReference(BASE_URI, "target_promoter");
//    TargetProduction.participations[ 1 ].participant.setReference(BASE_URI, "target_gene");
//    TargetProduction.participations[ 2 ].participant.setReference(BASE_URI, "target_protein");
//	
//    CRISPRRepression.participations.create(BASE_URI, "CRISPRRepression/inhibitor", v );
//    CRISPRRepression.participations.create(BASE_URI, "CRISPRRepression/promoter", v );
//
//    CRISPRRepression.participations["sys-bio.org/Participation/CRISPRRepression/inhibitor/1.0.0"].roles.set( SBO_INHIBITOR );
//    CRISPRRepression.participations["sys-bio.org/Participation/CRISPRRepression/inhibitor/1.0.0"].participant.set( cas9_grna_complex.identity.get() ); // This syntax allows the user to set a reference using an object. This achieves the same end results as setReference
//
//    CRISPRRepression.participations["sys-bio.org/Participation/CRISPRRepression/promoter/1.0.0"].roles.set( SBO_PROMOTER );
//    CRISPRRepression.participations["sys-bio.org/Participation/CRISPRRepression/promoter/1.0.0"].participant.set( target_promoter.identity.get() );
//
//    // Iterate through objects (black diamond properties in UML)
//    for( auto i_p = Cas9ComplexFormation.participations.begin(); i_p != Cas9ComplexFormation.participations.end(); i_p++)
//    {
//        Participation& p = (*i_p);
//        cout << p.identity.get() << endl;
//        cout << p.roles.get() << endl;
//    }
//    
//    // Iterate through references (white diamond properties in UML)
//    AB.roles.add(SBO "0000253");  // Appends the synonymous SBO term "non-covalent complex" to the list of roles for this Participation
//    for (auto i_role = AB.roles.begin(); i_role != AB.roles.end(); i_role++)
//    {
//        string role = *i_role;
//        cout << role << endl;
//    }
//    
//    // Specify the order of abstract genetic components using SequenceConstraints
//    TargetPromoter.sequenceConstraints.create(BASE_URI, "0", v);
//    TargetPromoter.sequenceConstraints[0].subject.setReference( BASE_URI, "TargetPromoter", v );
//    TargetPromoter.sequenceConstraints[0].object.setReference( BASE_URI, "TargetGene", v );
//    TargetPromoter.sequenceConstraints[0].restriction.set( SBOL_RESTRICTION_PRECEDES );
//    
//    // CRPbCircuit Module
//    Sequence& CRPbPromoterSeq = *new Sequence(BASE_URI, "CRPbPromoterSeq", v, "GCTCCGAATTTCTCGACAGATCTCATGTGATTACGCCAAGCTACGGGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTTCTGTCCTCCGAGCGGAGACTCTAGATACCTCATCAGGAACATGTTGGAATTCTAGGCGTGTACGGTGGGAGGCCTATATAAGCAGAGCTCGTTTAGTGAACCGTCAGATCGCCTCGAGTACCTCATCAGGAACATGTTGGATCCAATTCGACC", SBOL_ENCODING_IUPAC);
//    CRPbPromoter.sequence.set( CRPbPromoterSeq.identity.get() );  // Set reference to Sequences.  Sequences are automatically added to the Document.  Careful though!  If the parent ComponentDefinition isn't already attached to a Document, the Sequence can't be added either
//    Sequence& seq = *new Sequence(BASE_URI, "EYFPSequence", v, "atggtgagcaagggcgaggagctgttcaccggggtggtgcccatcctggtcgagctggacggcgacgtaaacggccacaagttcagcgtgtccggcgagggcgagggcgatgccacctacggcaagctgaccctgaagttcatctgcaccaccggcaagctgcccgtgccctggcccaccctcgtgaccaccttcggctacggcctgcaatgcttcgcccgctaccccgaccacatgaagctgcacgacttcttcaagtccgccatgcccgaaggctacgtccaggagcgcaccatcttcttcaaggacgacggcaactacaagacccgcgccgaggtgaagttcgagggcgacaccctggtgaaccgcatcgagctgaagggcatcgacttcaaggaggacggcaacatcctggggcacaagctggagtacaactacaacagccacaacgtctatatcatggccgacaagcagaagaacggcatcaaggtgaacttcaagatccgccacaacatcgaggacggcagcgtgcagctcgccgaccactaccagcagaacacccccatcggcgacggccccgtgctgctgcccgacaaccactacctgagctaccagtccgccctgagcaaagaccccaacgagaagcgcgatcacatggtcctgctggagttcgtgaccgccgccgggatcactctcggcatggacgagctgtacaagtaataa", SBOL_ENCODING_IUPAC);
//    EYFPGene.sequence.set(seq.identity.get());
//    doc.add<Sequence>(seq);
//    doc.write("CRISPR_example.xml");
//    //doc.write("CRISPR_example2.xml");
//    doc.read("CRISPR_example.xml");
//    doc.write("CRISPR_example2.xml");

    
//    ModuleDefinition& CRISPRTemplate = *new ModuleDefinition(BASE_URI "CRISPRTemplate");
//    ModuleDefinition& CRPbCircuit = *new ModuleDefinition(BASE_URI "CRPbCircuit");
//    Host& strainBB1 = *new Host(BASE_URI "BB1");
//    
//    strainBB1.modules.add( CRISPRTemplate );
//    strainBB1.modules.add( CRPbCircuit );
//    
//    doc.add < Host > (strainBB1);
//    doc.add < ModuleDefinition > (CRISPRTemplate);
//    doc.add < ModuleDefinition > (CRPbCircuit);
//    doc.write("Host_example.xml");

    //    Host& J04450_pSB1A2 = *new Host(BASE_URI "J04450_pSB1A2");
    //    Host& SS37 = *new Host(BASE_URI "SS37");
    //    Host& SS154 = *new Host(BASE_URI "SS154");
    //    Host& SS146 = *new Host(BASE_URI "SS146");
    //    Host& SS143 = *new Host(BASE_URI "SS143");
    //    Host& SS157 = *new Host(BASE_URI "SS157");
    //    Host& SS12 = *new Host(BASE_URI "SS12");
    //    Host& SS15 = *new Host(BASE_URI "SS15");
    //    Host& SS184 = *new Host(BASE_URI "SS184");
    //    Host& SS181 = *new Host(BASE_URI "SS181");
    //    Host& SS182 = *new Host(BASE_URI "SS182");
    //    Host& SS189 = *new Host(BASE_URI "SS189");
    //
    //
    ////    doc.add<Host>(J04450_pSB1A2);
    ////    doc.add<Host>(SS37);
    ////    doc.add<Host>(SS154);
    ////    doc.add<Host>(SS146);
    ////    doc.add<Host>(SS37);
    ////    doc.add<Host>(SS143);
    ////    doc.add<Host>(SS157);
    ////    doc.add<Host>(SS12);
    //    doc.add<Host>(SS15);
    //    doc.add<Host>(SS184);
    //    doc.add<Host>(SS181);
    //    doc.add<Host>(SS182);
    //    doc.add<Host>(SS189);
    //
    //    ModuleDefinition& C = *new ModuleDefinition(BASE_URI "C");
    //    ModuleDefinition& M = *new ModuleDefinition(BASE_URI "M");
    //    ModuleDefinition& Y = *new ModuleDefinition(BASE_URI "Y");
    //    ModuleDefinition& K = *new ModuleDefinition(BASE_URI "K");
    //    ModuleDefinition& CMYK = *new ModuleDefinition(BASE_URI "CMYK");
    //
    //    doc.add<ModuleDefinition>(C);
    //    doc.add<ModuleDefinition>(M);
    //    doc.add<ModuleDefinition>(Y);
    //    doc.add<ModuleDefinition>(K);
    //    doc.add<ModuleDefinition>(CMYK);
    //
    //    SS184.modules.add(C);
    //    SS15.modules.add(M);
    //    SS181.modules.add(Y);
    //    SS182.modules.add(K);
    //    SS189.modules.add(CMYK);
    //
    //    SS15.children.add(SS189);
    //    SS184.children.add(SS189);
    //    SS182.children.add(SS189);
    //    SS189.parents.add(SS15);
    //    SS189.parents.add(SS184);
    //    SS189.parents.add(SS181);
    //    SS189.parents.add(SS182);
    //    
    //    doc.write("CMYK_versioning");


}
