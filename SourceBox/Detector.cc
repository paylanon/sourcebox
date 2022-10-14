#include "Detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{

}

MySensitiveDetector::~MySensitiveDetector()
{

}

void MySensitiveDetector::Initialize(G4HCofThisEvent* HCE)
{

}

G4bool MySensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist)
{
	G4Track* track = aStep->GetTrack();

	G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint* postStepPoint = aStep->GetPostStepPoint();

	auto Edep = aStep->GetTotalEnergyDeposit();
	auto Ed = aStep->GetDeltaEnergy();
	auto Eki = preStepPoint->GetKineticEnergy();
	auto Ekf = postStepPoint->GetKineticEnergy();

	// G4double Edep_after = postStepPoint->GetTotalEnergy();

	// G4ThreeVector posNeutron = preStepPoint->GetPosition();

	// G4cout << "Neutron hit position: " << posNeutron << G4endl;

	G4String volumeName = preStepPoint->GetPhysicalVolume()->GetName();

	// G4double Ekin_before = preStepPoint->GetKineticEnergy();
	// G4double Ekin_after = postStepPoint->GetKineticEnergy();
	// G4double Ekin_delta = Ekin_before - Ekin_after;

	auto man = G4AnalysisManager::Instance();
	G4int detID = 0;

	if (volumeName == "physHDPECube1") {

		detID = 1;
		man->FillH1(0, Edep);
	}

	if (volumeName == "physHDPECube2") {
		
		detID = 2;
		man->FillH1(1, Edep);
	}

	if (volumeName == "physSteelSafe") {
		
		detID = 3;
		man->FillH1(2, Edep);
	}

	// G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();


	man->FillNtupleIColumn(0, detID);
	man->FillNtupleDColumn(1, Edep);
	man->FillNtupleDColumn(2, Ed);
	man->FillNtupleDColumn(3, Eki);
	man->FillNtupleDColumn(4, Ekf);
	man->AddNtupleRow(0);

	// Position
	// man->FillNtupleIColumn(0, evt);
	// man->FillNtupleDColumn(1, posNeutron[0]);
	// man->FillNtupleDColumn(2, posNeutron[1]);
	// man->FillNtupleDColumn(3, posNeutron[2]);
	// man->AddNtupleRow(0);

	return true;

}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE)
{

}