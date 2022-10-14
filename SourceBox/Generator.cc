#include "Generator.hh"

#include "Randomize.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	// Neutron Source

	fParticleGun = new G4GeneralParticleSource();

	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName = "neutron";
	G4ParticleDefinition* particle = particleTable->FindParticle("neutron");

	fParticleGun->SetParticleDefinition(particle);

	// PARTICLE SOURCE POSITION
	G4ThreeVector pos(0., 0., 0.);

	fParticleGun->SetParticlePosition(pos);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{

	// // GUN MOMENTUM: ISOTROPIC

	// G4double twopi = 2 * 3.141592653589793238; // 2π

 // 	G4double cosTheta = 2 * G4UniformRand() - 1.;
 // 	G4double phi = twopi * G4UniformRand();
 // 	G4double sinTheta = std::sqrt(1. - cosTheta * cosTheta);

 // 	G4double ux = sinTheta * std::cos(phi);
 //    G4double uy = sinTheta * std::sin(phi);
 //    G4double uz = cosTheta;
	// G4ThreeVector mom(ux, uy, uz);

	//fParticleGun->SetParticleMomentumDirection(mom);

	fParticleGun->GeneratePrimaryVertex(anEvent);

}