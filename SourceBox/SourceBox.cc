#include <iostream>
#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "QBBC.hh"

#include "Construction.hh"
#include "Physics.hh"
#include "Action.hh"


int main(int argc, char** argv)
{
	// PRE-PACKAGED PHYSICS LIST

	G4VModularPhysicsList* physicsList = new QBBC;
	physicsList->SetVerboseLevel(1);

	G4RunManager* runManager = new G4RunManager();
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(physicsList);
	runManager->SetUserInitialization(new MyActionInitialization());
	runManager->Initialize();

	G4UIExecutive* ui = new G4UIExecutive(argc,argv);
	G4VisManager* visManager = new G4VisExecutive();

	visManager->Initialize();

	G4UImanager* UImanager = G4UImanager::GetUIpointer();

	UImanager->ApplyCommand("/vis/open OGL");
	UImanager->ApplyCommand("/vis/drawVolume");
	UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
	UImanager->ApplyCommand("/vis/scene/add/trajectories smooth rich");

	// Palette

	//UImanager->ApplyCommand("/vis/modeling/trajectories/drawByParticleID-0/set neutron black");
	UImanager->ApplyCommand("/vis/viewer/set/background grey");

	UImanager->ApplyCommand("/vis/geometry/set/colour logicHDPECube1 0 0.7 0.6 0.9 .3");
	UImanager->ApplyCommand("/vis/geometry/set/colour logicHDPECube2 0 0.72 0.62 0.92 .3");
	UImanager->ApplyCommand("/vis/geometry/set/colour logicSteelSafe 0 0.5 0.5 0.5 .3");
	UImanager->ApplyCommand("/vis/geometry/set/colour logicBound1 0 0.5 0.5 0.5 .1");
	UImanager->ApplyCommand("/vis/geometry/set/colour logicBound2 0 0.5 0.5 0.5 .05");
	//UImanager->ApplyCommand("/vis/viewer/set/style surface");
	//UImanager->ApplyCommand("/vis/viewer/set/hiddenMarker true");
	UImanager->ApplyCommand("/vis/viewer/set/viewpointThetaPhi 120 150");



	ui->SessionStart();

	return 0;
}

