#define BASE_URI "http://sys-bio.org"
#define RAPTOR_STATIC
#define BIOPAX_DNA "http://www.biopax.org/release/biopax-level3.owl#DnaRegion"
#define BIOPAX_RNA "http://www.biopax.org/release/biopax-level3.owl#RnaRegion"
#define BIOPAX_PROTEIN "http://www.biopax.org/release/biopax-level3.owl#Protein"
#define BIOPAX_SMALL_MOLECULE "http://www.biopax.org/release/biopax-level3.owl#SmallMolecule"
#define BIOPAX_COMPLEX "http://www.biopax.org/release/biopax-level3.owl#Complex"
#define SO_PROMOTER "http://identifiers.org/so/SO:0000167"
#define SBO_NON_COVALENT_BINDING ""
#define SBO_PROMOTER ""

#include "sbol.h"

#include <iostream>

using namespace std;
using namespace sbol;

int main()
{
	Document& doc = Document();
	string version = "1.0.0";

	// Here we use CamelCase for displayID's, to distinguish Definitions from instances
	ModuleDefinition& CRISPR_Template = ModuleDefinition(BASE_URI, "CRISPR_Template", "", "", "", "", version);
	ComponentDefinition& cd1 = ComponentDefinition(BASE_URI, "Cas9", BIOPAX_PROTEIN, "", "", "", version);
	ComponentDefinition& cd2 = ComponentDefinition(BASE_URI, "GuideRNA", BIOPAX_RNA, "", "", "", version);
	ComponentDefinition& cd3 = ComponentDefinition(BASE_URI, "Cas9-GuideRNAComplex", BIOPAX_COMPLEX, "", "", "", version);
	ComponentDefinition& cd4 = ComponentDefinition(BASE_URI, "CRPbTargetPromoter", BIOPAX_DNA, SO_PROMOTER, "", "", version);
	doc.add<ComponentDefinition>(cd1);
	doc.add<ComponentDefinition>(cd2);
	doc.add<ComponentDefinition>(cd3);
	doc.add<ComponentDefinition>(cd4);
	doc.add<ModuleDefinition>(CRISPR_Template);

	// Here we use lowercase and underscores to distinguish instances of Component Definitions
	FunctionalComponent& fc1 = FunctionalComponent(BASE_URI, "cas9");
	fc1.definition.set(BASE_URI "/Cas9/1.0.0");
	FunctionalComponent& fc2 = FunctionalComponent(BASE_URI, "guide_rna");
	fc2.definition.set(BASE_URI "/GuideRNA/1.0.0");
	FunctionalComponent& fc3 = FunctionalComponent(BASE_URI, "cas9-guide_rna_complex");
	fc3.definition.set(BASE_URI "/Cas9-GuideRNAComplex/1.0.0");
	FunctionalComponent& fc4 = FunctionalComponent(BASE_URI, "crpb_target_promoter");
	fc4.definition.set(BASE_URI "/TargetPromoter/1.0.0");

	Interaction& Cas9ComplexFormation = Interaction(BASE_URI, "cas9_complex_formation");
	Cas9ComplexFormation.types.add(SBO_NON_COVALENT_BINDING);
	CRISPR_Template.interactions.add(Cas9ComplexFormation);
	
	Participation& p1 = Participation(BASE_URI, "A");
	Participation& p2 = Participation(BASE_URI, "B");
	Participation& p3 = Participation(BASE_URI, "AB");

	p1.roles.add(SBO_REACTANT);
	p2.roles.add(SBO_REACTANT);
	p3.roles.add(SBO_PRODUCT);

	p1.participant.add(BASE_URI "/cas9");
	p2.participant.add(BASE_URI "/guide_rna");
	p3.participant.add(BASE_URI "/cas9-guide_rna_complex");

	Cas9ComplexFormation.participations.add(p1);
	Cas9ComplexFormation.participations.add(p2);
	Cas9ComplexFormation.participations.add(p3);

	Interaction& EYFP_production = Interaction(BASE_URI, "target_production");
	EYFP_production.types.add(SBO_GENETIC_PRODUCTION);
	CRISPR_Template.interactions.add(EYFP_production);

	EYFP_production.participations.create(BASE_URI "promoter");
	EYFP_production.participations.get(BASE_URI "promoter").roles.add(SBO_PROMOTER);
	EYFP_production.participations.create(BASE_URI "gene_product");
	EYFP_production.participations.get(BASE_URI "gene_product").roles.add(SBO_PRODUCT);

	EYFP_production.participations.get(BASE_URI "promoter").participant.add(BASE_URI "crpb_target_promoter");
	EYFP_production.participations.get(BASE_URI "gene").participant.add(BASE_URI "/target_gene/1.0.0");

	

	doc.write("CRISPR_example.xml");
	return 0;
}
