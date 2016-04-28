#pragma once
#include "Vektoria\Root.h"
#include "MaterialLoader.h"

using namespace Vektoria;

class CGeoLoader
{
	
	public:
		static CGeoLoader& instance()
		{
			static CGeoLoader *instance = new CGeoLoader();
			return *instance;
		}

	void Init();

	CGeo* getShip();
	CGeo* getFightDrone();
	CGeo* getLaser();
	CGeo* getDesk();
	CGeo* getPlasma();

	//GUI Methoden
	CGeoQuad* getRahmenDroneCarrier();
	CGeoQuad* getRahmenTestShip();

	CGeoQuad* getLebensAnzeige();
	CGeoQuad* getLebensAnzeigeHintergrund();
	CGeoQuad* getLebensAnzeigeSchild();
	CGeoQuad* getLebensAnzeigeLeben();

	CMaterialLoader *m_Materialloader;

	//Ship
	//Carrier 
	CGeo *m_CarrierBase;
	CFileWavefront m_FileWavefrontCarrierBase;
	CGeo *m_CarrierOrbitFront;
	CFileWavefront m_FileWavefrontCarrierOrbitFront;
	CGeo *m_CarrierOrbitMiddle;
	CFileWavefront m_FileWavefrontCarrierOrbitMiddle;
	CGeo *m_CarrierOrbitRear;
	CFileWavefront m_FileWavefrontCarrierOrbitRear;
	CGeo *m_CarrierDrone;
	CFileWavefront m_FileWacefrontCarrierDrone;

	//Testing
	CGeo *m_ShipTesting;
	CFileWavefront m_FileWavefrontShipTesting;

	//Weapon
	CGeo *m_WeaponTesting;
	CFileWavefront m_FileWavefrontWeaponTesting;

	//Environment
	//Desk
	CGeo *m_EnvironmentDesk;
	CFileWavefront m_FilewavvefrontEnvironmentDesk;

	//Plasma
	CGeoCube m_Plasma;

	///////
	//GUI//
	///////
	//Rahmen
	CGeoQuad m_RahmenDroneCarrier;
	CGeoQuad m_RahmenTestShip;

	//LebensAnzeige
	CGeoQuad m_LebensAnzeige;
	CGeoQuad m_LebensAnzeigeHintergrund;
	CGeoQuad m_LebensAnzeigeSchild;
	CGeoQuad m_LebensAnzeigeLeben;
private:
	CGeoLoader();
	~CGeoLoader();
};

