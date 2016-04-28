#include "GeoLoader.h"


CGeoLoader::CGeoLoader()
{
}


CGeoLoader::~CGeoLoader()
{
}

void CGeoLoader::Init()
{
	m_Materialloader = &m_Materialloader->instance();

	//Ship
	//Carrier 

	m_CarrierBase = m_FileWavefrontCarrierBase.LoadGeoTriangleList("Modelle\\Traeger\\Traeger_base.obj"); 
	m_CarrierOrbitFront = m_FileWavefrontCarrierOrbitFront.LoadGeoTriangleList("Modelle\\Traeger\\Traeger_Ring_front.obj");
	m_CarrierOrbitMiddle = m_FileWavefrontCarrierOrbitMiddle.LoadGeoTriangleList("Modelle\\Traeger\\Traeger_Ring_mid.obj");
	m_CarrierOrbitRear = m_FileWavefrontCarrierOrbitRear.LoadGeoTriangleList("Modelle\\Traeger\\Traeger_Ring_rear.obj");
	m_CarrierDrone = m_FileWacefrontCarrierDrone.LoadGeoTriangleList("Modelle\\Drone\\Drone.obj");
	


	m_ShipTesting = m_FileWavefrontShipTesting.LoadGeoTriangleList("Modelle\\Ship.obj", true);
	m_WeaponTesting = m_FileWavefrontWeaponTesting.LoadGeoTriangleList("Modelle\\Laser.obj", true);


	m_EnvironmentDesk = m_FilewavvefrontEnvironmentDesk.LoadGeoTriangleList("Modelle\\Table_v1.obj", true);
	m_Plasma.Init(CHVector(0.1f, 0.1f, 0.1f), m_Materialloader->getPlasma());

	///////
	//GUI//
	///////
	//Rahmen
	m_RahmenDroneCarrier.Init(6.0F, 6.0F, m_Materialloader->getRahmenDroneCarrier());
	m_RahmenTestShip.Init(1.5F, 1.5F, m_Materialloader->getRahmenTestShip());

	//LebensAnzeige
	m_LebensAnzeige.Init(10.5F, 0.5F, m_Materialloader->getLebensAnzeige());
	
	m_LebensAnzeigeHintergrund.Init(10.1F, 0.1F, m_Materialloader->getLebensAnzeigeHintergrund());
	m_LebensAnzeigeSchild.Init(0.1F, 10.1F, m_Materialloader->getLebensAnzeigeSchild());
	m_LebensAnzeigeLeben.Init(0.1F,10.1F, m_Materialloader->getLebensAnzeigeLeben());

}

CGeo* CGeoLoader::getShip()
{
	return m_ShipTesting;
}

CGeo* CGeoLoader::getLaser()
{
	return m_WeaponTesting;
}

CGeo* CGeoLoader::getDesk()
{
	return m_EnvironmentDesk;
}

CGeo* CGeoLoader::getPlasma()
{
	return &m_Plasma;
}

CGeo* CGeoLoader::getFightDrone()
{
	return m_CarrierDrone;
}

CGeoQuad* CGeoLoader::getRahmenDroneCarrier()
{
	return &m_RahmenDroneCarrier;
}

CGeoQuad* CGeoLoader::getRahmenTestShip()
{
	return &m_RahmenTestShip;
}

CGeoQuad* CGeoLoader::getLebensAnzeige()
{
	return &m_LebensAnzeige;
}
CGeoQuad* CGeoLoader::getLebensAnzeigeHintergrund()
{
	return &m_LebensAnzeigeHintergrund;
}
CGeoQuad* CGeoLoader::getLebensAnzeigeSchild()
{
	return &m_LebensAnzeigeSchild;
}
CGeoQuad* CGeoLoader::getLebensAnzeigeLeben()
{
	return &m_LebensAnzeigeLeben;
}