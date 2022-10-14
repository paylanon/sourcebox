#include "Construction.hh"
#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"

// MAEVE

#include "G4PhysicalConstants.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
	// MATERIALS
	G4NistManager* nist = G4NistManager::Instance();
	G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");

	// Silica
	G4Material* SiO2 = new G4Material("SiO2", 2.2021*g/cm3, 2);
	SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
	SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	// Water
	G4Material* H2O = new G4Material("H2O", 2.2021*g/cm3, 2);
	H2O->AddElement(nist->FindOrBuildElement("H"), 2);
	H2O->AddElement(nist->FindOrBuildElement("O"), 1);

	// Carbon
	G4Element* C = nist->FindOrBuildElement("C");

	// Iron
	G4Element* Fe = nist->FindOrBuildElement("Fe");

	// Chromium
	G4Element* Cr = nist->FindOrBuildElement("Cr");

	// Aerogel 
	// G4Material* Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
	// Aerogel->AddMaterial(SiO2, 62.5*perCent);
	// Aerogel->AddMaterial(H2O, 36.4*perCent);
	// Aerogel->AddElement(C, 1*perCent);

	// Lead

	G4Element* Pb = nist->FindOrBuildElement("Pb");

	G4Material* Lead = new G4Material("Lead", 11.29*g/cm3, 1);
	Lead->AddElement(Pb, 100*perCent);

	// HDPE
	//G4Material* CH2 = new G4Material("CH2", 940*kg/m3, 2);
	//CH2->AddElement(C,1);
	//CH2->AddElement(nist->FindOrBuildElement("H"), 2);

	// Steel: 88.3% C, 
	G4Material* SSteel = new G4Material("SSteel", 7600*kg/m3, 3);
	SSteel->AddElement(Fe, 88.3*perCent);
	SSteel->AddElement(Cr, 10.5*perCent);
	SSteel->AddElement(C, 1.2*perCent);

	//// MAEVE START

	  // G4Material* Copper = nist->FindOrBuildMaterial("G4_Cu");
  	//   G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
  	//   G4Material* Germanium = nist->FindOrBuildMaterial("G4_Ge");
  	//   G4Material* Magnesium = nist->FindOrBuildMaterial("G4_Mg");
  	//   G4Material* Aluminum = nist->FindOrBuildMaterial("G4_Al");
  	//   G4Material* Mylar = nist->FindOrBuildMaterial("G4_MYLAR");
  	//   G4Material* Air  = nist->FindOrBuildMaterial("G4_AIR");
 	 //  G4Material* Stainless = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
 	 //  G4Material* Polystyrene = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  	//   G4Material* Titanium = nist->FindOrBuildMaterial("G4_Ti");
 	 //  G4Material* Tungsten = nist->FindOrBuildMaterial("G4_W");
 	 //  G4Material* Teflon = nist->FindOrBuildMaterial("G4_TEFLON");

	 	// // vacuum
	  // G4double density    = universe_mean_density;    //from PhysicalConstants.h
	  // G4double pressure    = 3.e-18*pascal;
	  // G4double temperature = 2.73*kelvin;
	  // G4Material* Vacuum = new G4Material("Vacuum", density, 1); // FIX THIS

	  // G4Element* elO = new G4Element("Oxygen",     "O",  8, 16.00*g/mole);
	  // G4Element* elN = new G4Element("Nitrogen",   "N",  7, 14.01*g/mole);
	  // G4Element* elH = new G4Element("Hydrogen",   "H",  1, 1.008*g/mole);
	  // G4Element* elC = new G4Element("Carbon",     "C",  6, 12.01*g/mole);
	  // G4Element* elTe = new G4Element("Tellurium", "Te", 52, 127.6*g/mole);
	  // G4Element* elCu = new G4Element("Copper",    "Cu", 29, 63.55*g/mole);
	  // G4Element* elZn = new G4Element("Zinc",      "Zn", 30, 65.38*g/mole);
	  // G4Element* elSn = new G4Element("Tin",       "Sn", 50, 118.710*g/mole);
	  // G4Element* elS = new G4Element("Sulfur",     "S",  16, 32.064*g/mole);
	  // G4Element* elK = new G4Element("Potassium",  "K",  19, 39.098*g/mole);
	  // G4Element* elLa = new G4Element("Lanthanum", "La", 57, 138.905*g/mole);
	  // G4Element* elLu = new G4Element("Lutetium",  "Lu", 71, 174.967*g/mole);
	  // G4Element* elPb = new G4Element("Lead",      "Pb", 82, 207.20*g/mole);
	  // G4Element* elAl = new G4Element("Aluminum",  "Al", 13, 26.982*g/mole);
	  // G4Element* elFe = new G4Element("Iron",      "Fe", 26, 55.845*g/mole);
	  // G4Element* elCa = new G4Element("Calcium",   "Ca", 20, 40.078*g/mole);
	  // G4Element* elNa = new G4Element("Sodium",    "Na", 11, 22.989770*g/mole);
	  // G4Element* elSi = new G4Element("Silicon",   "Si", 14, 28.0855*g/mole);
	  // G4Element* elCl = new G4Element("Chlorine",  "Cl", 19, 35.45*g/mole);
	  // G4Element* elNi = new G4Element("Nickel",    "Ni", 28, 68.69*g/mole);
	  // G4Element* elCo = new G4Element("Cobalt",    "Co", 27, 58.93*g/mole);
	  // G4Element* elMn = new G4Element("Manganese", "Mn", 25, 54.94*g/mole);
	  // G4Element* elW = new G4Element("Tungsten", "W", 74, 183.84*g/mole);
	  
	  // // KCl
	  // density = 1.98*g/cm3;
	  // G4Material* KCl = new G4Material("KCl", density, 2);
	  // KCl->AddElement(elK, 1);
	  // KCl->AddElement(elCl, 1);

	  // // kovar
	  // density = 8.0*g/cm3;
	  // G4Material* Kovar = new G4Material("Kovar", density, 5);
	  // Kovar->AddElement(elFe, 53.5*perCent);
	  // Kovar->AddElement(elNi, 29*perCent);
	  // Kovar->AddElement(elCo, 17*perCent);
	  // Kovar->AddElement(elSi, 0.2*perCent);
	  // Kovar->AddElement(elMn, 0.3*perCent);

	  // // quartz (SiO4)
	  // density = 2.65*g/cm3;
	  // G4Material* Quartz = new G4Material("Quartz", density, 2);
	  // Quartz->AddElement(elSi, 1);
	  // Quartz->AddElement(elO, 4);
	  
	  // // Rhyolite composition
	  // G4Material* Silica = new G4Material("Silica", 2.648*g/cm3, 2);
	  // Silica->AddElement(elSi, 1);
	  // Silica->AddElement(elO, 2);

	  // G4Material* Ceramic = Silica;
	  
	  // G4Material* Soda = new G4Material("Soda", density= 2.16*g/cm3, 4);
	  // Soda->AddElement(elNa, 1);
	  // Soda->AddElement(elH, 1);
	  // Soda->AddElement(elC, 1);
	  // Soda->AddElement(elO, 3);
	  
	  // G4Material* Lime = new G4Material("Lime", 3.34*g/cm3, 2);
	  // Lime->AddElement(elCa, 1);
	  // Lime->AddElement(elO, 1);
	  
	  // G4Material* Magnetite = new G4Material("Magnetite", 5.0*g/cm3, 2);
	  // Magnetite->AddElement(elFe, 3);
	  // Magnetite->AddElement(elO, 4);
	  
	  // G4Material* Alumina = new G4Material("Alumina", 3.95*g/cm3, 2);
	  // Alumina->AddElement(elAl, 2);
	  // Alumina->AddElement(elO, 3);
	  
	  // G4Material* Rhyolite = new G4Material("Rhyolite", 2.5*g/cm3, 5);
	  // Rhyolite->AddMaterial(Silica, 80*perCent);
	  // Rhyolite->AddMaterial(Alumina, 15*perCent);
	  // Rhyolite->AddMaterial(Magnetite, 1*perCent);
	  // Rhyolite->AddMaterial(Soda, 2*perCent);
	  // Rhyolite->AddMaterial(Lime, 2*perCent);

	// MAEVE END


	// WORLD
	// WORLD Solid Volume
	G4Box* solidWorld = new G4Box("solidWorld", 2*m, 2*m, 2*m);

	// WORLD Logical Volume
	G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	// WORLD Physical Volume
	G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

	// Envelope

	// G4Material* Env_mat = nist->FindOrBuildMaterial("G4_AIR");
	// G4Box* solidEnv = new G4Box("Envelope", 1*m, 1*m, 1*m);

	// G4LogicalVolume* logicEnv = new G4LogicalVolume(solidEnv, Env_mat, "Envelope");

	// G4VPhysicalVolume* physEnv =  new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicEnv, "Envelope", logicWorld, false, 0, true);

	// // RADIATOR
	// G4Box* solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);

	// G4LogicalVolume* logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");

	// G4VPhysicalVolume* physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicRadiator, "physRadiator", logicWorld, false, 0, true);

	// GEOMETRY

	// Distant Detector

	G4Material* Bound2_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
	G4ThreeVector Bound2_pos = G4ThreeVector(0., 0., 0.);

	G4double Bound2_dx = ((12.1*2.54)+100)*cm;
	G4double Bound2_dy = ((12.1*2.54)+100)*cm;
	G4double Bound2_dz  = ((12.1*2.54)+100)*cm;
	
	G4Box* solidBound2 = new G4Box("solidBound2", 0.5*Bound2_dx, 0.5*Bound2_dy, 0.5*Bound2_dz);

	G4LogicalVolume* logicBound2 = new G4LogicalVolume(solidBound2, Bound2_mat, "logicBound2");

	G4VPhysicalVolume* physBound2 = new G4PVPlacement(0, Bound2_pos, logicBound2, "physBound2", logicWorld, false, 0, true);

	//

	G4Material* Void2_mat = nist->FindOrBuildMaterial("G4_AIR");
	G4ThreeVector Void2_pos = G4ThreeVector(0., 0., 0.);

	G4double Void2_dx = ((12*2.54)+100)*cm;
	G4double Void2_dy = ((12*2.54)+100)*cm;
	G4double Void2_dz  = ((12*2.54)+100)*cm;
	
	G4Box* solidVoid2 = new G4Box("solidVoid2", 0.5*Void2_dx, 0.5*Void2_dy, 0.5*Void2_dz);

	G4LogicalVolume* logicVoid2 = new G4LogicalVolume(solidVoid2, Void2_mat, "logicVoid2");

	G4VPhysicalVolume* physVoid2 = new G4PVPlacement(0, Void2_pos, logicVoid2, "physVoid2", logicBound2, false, 0, true);

	// Distant Detector

	G4Material* Bound1_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
	G4ThreeVector Bound1_pos = G4ThreeVector(0., 0., 0.);

	G4double Bound1_dx = ((12.1*2.54)+50)*cm;
	G4double Bound1_dy = ((12.1*2.54)+50)*cm;
	G4double Bound1_dz  = ((12.1*2.54)+50)*cm;
	
	G4Box* solidBound1 = new G4Box("solidBound1", 0.5*Bound1_dx, 0.5*Bound1_dy, 0.5*Bound1_dz);

	G4LogicalVolume* logicBound1 = new G4LogicalVolume(solidBound1, Bound1_mat, "logicBound1");

	G4VPhysicalVolume* physBound1 = new G4PVPlacement(0, Bound1_pos, logicBound1, "physBound1", logicVoid2, false, 0, true);

	//

	G4Material* Void1_mat = nist->FindOrBuildMaterial("G4_AIR");
	G4ThreeVector Void1_pos = G4ThreeVector(0., 0., 0.);

	G4double Void1_dx = ((12*2.54)+50)*cm;
	G4double Void1_dy = ((12*2.54)+50)*cm;
	G4double Void1_dz  = ((12*2.54)+50)*cm;
	
	G4Box* solidVoid1 = new G4Box("solidVoid1", 0.5*Void1_dx, 0.5*Void1_dy, 0.5*Void1_dz);

	G4LogicalVolume* logicVoid1 = new G4LogicalVolume(solidVoid1, Void1_mat, "logicVoid1");

	G4VPhysicalVolume* physVoid1 = new G4PVPlacement(0, Void1_pos, logicVoid1, "physVoid1", logicBound1, false, 0, true);

	// Exterior Detector

	G4Material* Exterior_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
	G4ThreeVector Exterior_pos = G4ThreeVector(0., 0., 0.);

	G4double Exterior_dx = (13.1*2.54)*cm;
	G4double Exterior_dy = (13.1*2.54)*cm;
	G4double Exterior_dz  = (13.1*2.54)*cm;
	
	G4Box* solidExterior = new G4Box("solidExterior", 0.5*Exterior_dx, 0.5*Exterior_dy, 0.5*Exterior_dz);

	G4LogicalVolume* logicExterior = new G4LogicalVolume(solidExterior, Exterior_mat, "logicExterior");

	G4VPhysicalVolume* physExterior = new G4PVPlacement(0, Exterior_pos, logicExterior, "physExterior", logicVoid1, false, 0, true);

	// Steel Safe

	G4Material* SteelSafe_mat = SSteel;
	G4ThreeVector SteelSafe_pos = G4ThreeVector(0., 0., 0.);

	G4double SteelSafe_dx = (13*2.54)*cm;
	G4double SteelSafe_dy = (13*2.54)*cm;
	G4double SteelSafe_dz  = (13*2.54)*cm;
	
	G4Box* solidSteelSafe = new G4Box("solidSteelSafe", 0.5*SteelSafe_dx, 0.5*SteelSafe_dy, 0.5*SteelSafe_dz);

	G4LogicalVolume* logicSteelSafe = new G4LogicalVolume(solidSteelSafe, SteelSafe_mat, "logicSteelSafe");

	G4VPhysicalVolume* physSteelSafe = new G4PVPlacement(0,SteelSafe_pos, logicSteelSafe, "physSteelSafe", logicExterior, false, 0, true);

	// Outer HDPE Cube

	G4Material* HDPECube2_mat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
	G4ThreeVector HDPECube2_pos = G4ThreeVector(0., 0., 0.);

	G4double HDPECube2_dx = (12*2.54)*cm;
	G4double HDPECube2_dy = (12*2.54)*cm;
	G4double HDPECube2_dz  = (12*2.54)*cm;
	
	G4Box* solidHDPECube2 = new G4Box("solidHDPECube2", 0.5*HDPECube2_dx, 0.5*HDPECube2_dy, 0.5*HDPECube2_dz);

	G4LogicalVolume* logicHDPECube2 = new G4LogicalVolume(solidHDPECube2, HDPECube2_mat, "logicHDPECube2");

	G4VPhysicalVolume* physHDPECube2 = new G4PVPlacement(0,HDPECube2_pos, logicHDPECube2, "physHDPECube2", logicSteelSafe, false, 0, true);

	// Inner HDPE Cube

	G4Material* HDPECube1_mat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
	G4ThreeVector HDPECube1_pos = G4ThreeVector(0., 0., 0.);

	G4double HDPECube1_dx = (10*2.54)*cm;
	G4double HDPECube1_dy = (10*2.54)*cm;
	G4double HDPECube1_dz  = (10*2.54)*cm;
	
	G4Box* solidHDPECube1 = new G4Box("solidHDPECube1", 0.5*HDPECube1_dx, 0.5*HDPECube1_dy, 0.5*HDPECube1_dz);

	G4LogicalVolume* logicHDPECube1 = new G4LogicalVolume(solidHDPECube1, HDPECube1_mat, "logicHDPECube1");

	G4VPhysicalVolume* physHDPECube1 = new G4PVPlacement(0,HDPECube1_pos, logicHDPECube1, "physHDPECube1", logicHDPECube2, false, 0, true);

	// Interior

	G4Material* Interior_mat = nist->FindOrBuildMaterial("G4_AIR");
	G4ThreeVector Interior_pos = G4ThreeVector(0., 0., 0.);

	G4double Interior_dx = (8*2.54)*cm;
	G4double Interior_dy = (8*2.54)*cm;
	G4double Interior_dz  = (8*2.54)*cm;
	
	G4Box* solidInterior = new G4Box("solidInterior", 0.5*Interior_dx, 0.5*Interior_dy, 0.5*Interior_dz);

	G4LogicalVolume* logicInterior = new G4LogicalVolume(solidInterior, Interior_mat, "logicInterior");

	G4VPhysicalVolume* physInterior = new G4PVPlacement(0, Interior_pos, logicInterior, "physInterior", logicHDPECube1, false, 0, true);

	// Detector1: solidExterior, logicExterior
	// Detector2: solidBound1, logicBound1


	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{

 	G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

 	// Detector 1

 	auto pDet1 = new MySensitiveDetector("pDetector1");
 	G4SDManager::GetSDMpointer()->AddNewDetector(pDet1);

 // 	G4VPrimitiveScorer* primitive1;
	// primitive1 = new G4PSEnergyDeposit("Edep1");
	// pDet1->RegisterPrimitive(primitive1);

 	// SetSensitiveDetector("logicExterior", pDet1);
 	SetSensitiveDetector("logicHDPECube1", pDet1);

 	// Detector 2

 	auto pDet2 = new MySensitiveDetector("pDetector2");
 	G4SDManager::GetSDMpointer()->AddNewDetector(pDet2);

 // 	G4VPrimitiveScorer* primitive2;
	// primitive2 = new G4PSEnergyDeposit("Edep2");
	// pDet2->RegisterPrimitive(primitive2);

 	// SetSensitiveDetector("logicBound1", pDet2);
 	SetSensitiveDetector("logicHDPECube2", pDet2);

 	// Detector 3
 	
 	auto pDet3 = new MySensitiveDetector("pDetector3");
 	G4SDManager::GetSDMpointer()->AddNewDetector(pDet3);

 // 	G4VPrimitiveScorer* primitive3;
	// primitive3 = new G4PSEnergyDeposit("Edep3");
	// pDet3->RegisterPrimitive(primitive3);

 	// SetSensitiveDetector("logicBound2", pDet3);
 	SetSensitiveDetector("logicSteelSafe", pDet3);
}
