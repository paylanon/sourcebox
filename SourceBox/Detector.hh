#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"



class MySensitiveDetector : public G4VSensitiveDetector
{
public:
	MySensitiveDetector(G4String name);
	~MySensitiveDetector();
	virtual void Initialize(G4HCofThisEvent* HCE);
	virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist);
	virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:
	G4LogicalVolume* logicHDPECube1;
	G4LogicalVolume* logicHDPECube2;
	G4LogicalVolume* logicSteelSafe;

};

#endif


