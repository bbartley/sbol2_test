#define BASE_URI "sys-bio.org"
#define RAPTOR_STATIC

#include "sbol.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace sbol;

int main()
{
	Document& doc = *new Document();

    std::string v = "1.0.0";  // Versioning uses Maven semantics
    
	// Here we use CamelCase for displayID's, to distinguish Definitions from instances
    ModuleDefinition& CRISPRTemplate = *new ModuleDefinition(BASE_URI, "CRISPRTemplate", v);
    ComponentDefinition& Cas9 = *new ComponentDefinition(BASE_URI, "Cas9", v, BIOPAX_PROTEIN);
    ComponentDefinition& GuideRNA = *new ComponentDefinition(BASE_URI, "GuideRNA", v, BIOPAX_RNA);
	ComponentDefinition& Cas9GuideRNAComplex = *new ComponentDefinition(BASE_URI, "Cas9-GuideRNAComplex", v, BIOPAX_COMPLEX);
	ComponentDefinition& TargetPromoter = *new ComponentDefinition(BASE_URI, "TargetPromoter", v, BIOPAX_DNA);
    ComponentDefinition& TargetGene = *new ComponentDefinition(BASE_URI, "TargetGene", v, BIOPAX_DNA);
    ComponentDefinition& TargetProtein = *new ComponentDefinition(BASE_URI, "TargetProtein", v, BIOPAX_PROTEIN);

    TargetPromoter.types.set(SO_PROMOTER);
    TargetGene.types.set(SO_CDS);
    
    doc.add<ModuleDefinition>(CRISPRTemplate);
    doc.add<ComponentDefinition>(Cas9);
	doc.add<ComponentDefinition>(GuideRNA);
	doc.add<ComponentDefinition>(Cas9GuideRNAComplex);
	doc.add<ComponentDefinition>(TargetPromoter);
    doc.add<ComponentDefinition>(TargetGene);
    doc.add<ComponentDefinition>(TargetProtein);

    Interaction& Cas9ComplexFormation = *new Interaction(BASE_URI, "complex_formation", v, SBO_NONCOVALENT_BINDING);
    Interaction& CRISPRRepression = *new Interaction(BASE_URI, "gene_inhibition", v, SBO_INHIBITION);
    Interaction& TargetProduction = *new Interaction(BASE_URI, "target_production", v, SBO_GENETIC_PRODUCTION);

    CRISPRTemplate.interactions.add(Cas9ComplexFormation);
    
	// Here we use lowercase and underscores to distinguish instances of Component Definitions
	FunctionalComponent& cas9 = *new FunctionalComponent(BASE_URI, "cas9");
    cas9.definition.set( Cas9.identity.get() );  // The set method is the simplest way to set a reference

    // setReference provides more specialized methods of setting references
    FunctionalComponent& gRNA = *new FunctionalComponent(BASE_URI, "guide_rna");
	gRNA.definition.setReference( "sys-bio.org/GuideRNA/1.0.0" );  // setReference can take a raw formatted URI; this is exactly the same as the set method
	
    FunctionalComponent& cas9_gRNA_complex = *new FunctionalComponent(BASE_URI, "cas9-guide_rna_complex");
	cas9_gRNA_complex.definition.setReference(BASE_URI, "Cas9-GuideRNAComplex", "1.0.0");  // setReference will also construct compliant URIs
	
    FunctionalComponent& target_promoter = *new FunctionalComponent(BASE_URI, "target_promoter");
	target_promoter.definition.setReference(BASE_URI, "TargetPromoter");  // By default appends version 1.0.0 to compliant URI

    FunctionalComponent& target_gene = *new FunctionalComponent(BASE_URI, "target_gene");
    target_gene.definition.setReference(BASE_URI, "TargetGene");
    
    FunctionalComponent& target_protein = *new FunctionalComponent(BASE_URI, "target_protein");
    target_protein.definition.setReference(BASE_URI, "TargetProtein");
    
    // Here we represent ComplexFormation as the reaction A + B = AB
	Participation& A = *new Participation(BASE_URI, "A", v, "sys-bio.org/cas9/1.0.0");
	Participation& B = *new Participation(BASE_URI, "B", v, "sys-bio.org/guide_rna/1.0.0");
	Participation& AB = *new Participation(BASE_URI, "AB", v, "sys-bio.org/cas9-guide_rna_complex/1.0.0");
    A.roles.set( SBO_REACTANT );
    B.roles.set( SBO_REACTANT );
    AB.roles.set( SBO_PRODUCT );
    
    Cas9ComplexFormation.participations.add(A);
	Cas9ComplexFormation.participations.add(B);
	Cas9ComplexFormation.participations.add(AB);

    // Iterate through objects (black diamond properties in UML)
    for( auto i_p = Cas9ComplexFormation.participations.begin(); i_p != Cas9ComplexFormation.participations.end(); i_p++)
    {
        Participation& p = (*i_p);
        cout << p.identity.get() << endl;
        cout << p.roles.get() << endl;
    }
    
    // Iterate through references (white diamond properties in UML)
    AB.roles.add(SBO "0000253");  // Appends the synonymous SBO term "non-covalent complex" to the list of roles for this Participation
    for (auto i_role = AB.roles.begin(); i_role != AB.roles.end(); i_role++)
    {
        string role = *i_role;
        cout << role << endl;
    }

	TargetProduction.participations.create(BASE_URI, "TargetProduction/promoter");  // The create method is general and not specialized for every class like libSBOLj's.
    TargetProduction.participations.create(BASE_URI, "TargetProduction/gene");
    TargetProduction.participations.create(BASE_URI, "TargetProduction/gene_product");
    
    // Child objects (corresponding to black diamonds in UML) can be accessed by uri
    TargetProduction.participations[ "sys-bio.org/TargetProduction/promoter/1.0.0" ].roles.set(SBO_PROMOTER);
    TargetProduction.participations[ "sys-bio.org/TargetProduction/gene/1.0.0" ].roles.set(SBO_PROMOTER);
    TargetProduction.participations[ "sys-bio.org/TargetProduction/gene_product/1.0.0" ].roles.set(SBO_PRODUCT);

    // Child objects can be dereferenced by numerical index, too.
    TargetProduction.participations[ 0 ].participant.setReference(BASE_URI, "target_promoter");
    TargetProduction.participations[ 1 ].participant.setReference(BASE_URI, "target_gene");
    TargetProduction.participations[ 2 ].participant.setReference(BASE_URI, "target_protein");
	
    CRISPRRepression.participations.create(BASE_URI, "CRISPRRepression/inhibitor" );
    CRISPRRepression.participations.create(BASE_URI, "CRISPRRepression/promoter" );

    CRISPRRepression.participations["sys-bio.org/CRISPRRepression/inhibitor/1.0.0"].roles.set( SBO_INHIBITOR );
    CRISPRRepression.participations["sys-bio.org/CRISPRRepression/inhibitor/1.0.0"].participant.set( cas9_gRNA_complex ); // This syntax allows the user to set a reference using an object. This achieves the same end results as setReference

    CRISPRRepression.participations["sys-bio.org/CRISPRRepression/promoter/1.0.0"].roles.set( SBO_PROMOTER );
    CRISPRRepression.participations["sys-bio.org/CRISPRRepression/promoter/1.0.0"].participant.set( target_promoter );

    // Start the CRPb Characterization Module
    ComponentDefinition& CRPbPromoter = *new ComponentDefinition(BASE_URI, "pCRPb", v, BIOPAX_DNA);
    ComponentDefinition& EYFPGene = *new ComponentDefinition(BASE_URI, "EYFPGene", v, BIOPAX_DNA);
    ComponentDefinition& EYFP = *new ComponentDefinition(BASE_URI, "EYFP", v, BIOPAX_PROTEIN);
    CRPbPromoter.types.set(SO_PROMOTER);
    EYFPGene.types.set(SO_CDS);
    
    // Set reference to Sequences.  Sequences are automatically added to the Document
    // Careful though!  If the parent ComponentDefinition isn't already attached to a Document, the Sequence can't be added either
    doc.add<ComponentDefinition>(CRPbPromoter);
    CRPbPromoter.sequence.set(*new Sequence(BASE_URI, "CRPbPromoterSeq", "GCTCCGAATTTCTCGACAGATCTCATGTGATTACGCCAAGCTACGGGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTACTGTCCTCCGAGCGGAGTTCTGTCCTCCGAGCGGAGACTCTAGATACCTCATCAGGAACATGTTGGAATTCTAGGCGTGTACGGTGGGAGGCCTATATAAGCAGAGCTCGTTTAGTGAACCGTCAGATCGCCTCGAGTACCTCATCAGGAACATGTTGGATCCAATTCGACC"));
    
	doc.write("CRISPR_example.xml");
    doc.read("CRISPR_example.xml");
    doc.write("CRISPR_example2.xml");
    return 0;
}
