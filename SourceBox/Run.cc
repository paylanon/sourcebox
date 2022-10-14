#include "Run.hh"

MyRunAction::MyRunAction()
{

}

MyRunAction::~MyRunAction()
{
	
}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();

	man->OpenFile("Output.root");

	// NTUPLE Construction
	man->CreateNtuple("Hits", "Hits");
	man->CreateNtupleIColumn("DetectorID");
	man->CreateNtupleDColumn("Edep");
	man->CreateNtupleDColumn("Edelta");
	man->CreateNtupleDColumn("Eki");
	man->CreateNtupleDColumn("Ekf");
	man->FinishNtuple();

	// HISTO Construction
	man->CreateH1("Edep1","1\" HDPE;x;y", 200, 0., 2.6);
	man->CreateH1("Edep2","2\" HDPE", 200, 0., 2.6);
	man->CreateH1("Edep3","Steel Safe", 200, 0., 2.6);

}

void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();

	man->Write();
	man->CloseFile();

}
