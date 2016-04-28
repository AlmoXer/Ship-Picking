#include "DroneCarrier.h"


CDroneCarrier::CDroneCarrier()
{


}


CDroneCarrier::~CDroneCarrier()
{
}

bool CDroneCarrier::Init(CPlayer *p_Player, Vektoria::CHVector p_Position)
{

	m_iBauteileAnz = 4;

	m_GeoLoader = &m_GeoLoader->instance();
	m_ShipHandler = &m_ShipHandler->instance();

	m_Rahmen.AddGeo(m_GeoLoader->getRahmenDroneCarrier());
	m_Rahmen.TranslateZDelta(0.5F);
	m_Rahmen.SetBillboard();


	m_LebensAnzeige.AddGeo(m_GeoLoader->getLebensAnzeige());
	//m_LebensAnzeige.Rotate(this->r());
	m_LebensAnzeige.TranslateZDelta(10.0F);	
	//m_LebensAnzeige.TranslateYDelta(5.1F);
	m_LebensAnzeige.SetBillboard();

	m_LebensAnzeigeHintergrund.AddGeo(m_GeoLoader->getLebensAnzeigeHintergrund());
	m_LebensAnzeigeHintergrund.SetBillboard();
	//m_LebensAnzeigeHintergrund.TranslateXDelta(-10.11F);
	m_LebensAnzeigeHintergrund.TranslateYDelta(5.1F);

	m_LebensAnzeigeLeben.AddGeo(m_GeoLoader->getLebensAnzeigeLeben());
	m_LebensAnzeigeLeben.SetBillboard();
	//m_LebensAnzeigeLeben.TranslateXDelta(-10.12F);
	m_LebensAnzeigeLeben.TranslateYDelta(5.1F);

	m_LebensAnzeigeSchild.AddGeo(m_GeoLoader->getLebensAnzeigeSchild());
	m_LebensAnzeigeSchild.SetBillboard();
	//m_LebensAnzeigeSchild.TranslateXDelta(-10.13F);
	m_LebensAnzeigeSchild.TranslateYDelta(5.1F);



	Name = "DroneCarrier";
	m_droneCount = 45;

	m_AttackTarget = nullptr;
	
	
	m_geoBase = m_GeoLoader->m_CarrierBase;  
	m_geoFront = m_GeoLoader->m_CarrierOrbitFront;
	m_geoMiddle = m_GeoLoader->m_CarrierOrbitMiddle;
	m_geoRear = m_GeoLoader->m_CarrierOrbitRear;
	
	this->AddGeo(m_geoBase);
	this->Translate(p_Position);
	this->RotateYDelta(HALFPI);
	/*
	m_DroneCarrier.AddGeo(m_geoBase);
	m_DroneCarrier.Translate(p_Position);
	m_DroneCarrier.RotateYDelta(HALFPI);
	*/
	m_Movement.init(this);
	moving = false;

	m_Orbit[0].init(this, "Orbit Front");
	m_Orbit[0].AddGeo(m_GeoLoader->m_CarrierOrbitFront);
	m_Orbit[0].TranslateZDelta(0.15f);

	m_Orbit[1].init(this, "Orbit Middle");
	m_Orbit[1].AddGeo(m_GeoLoader->m_CarrierOrbitMiddle);
	m_Orbit[1].TranslateZDelta(1.4f);

	m_Orbit[2].init(this, "Orbit Rear");
	m_Orbit[2].AddGeo(m_GeoLoader->m_CarrierOrbitRear);
	m_Orbit[2].TranslateZDelta(2.8f);

	m_Orbit[3].init(this, "Orbit only because of Reasons");
	m_Orbit[3].AddGeo(m_GeoLoader->m_CarrierOrbitRear);
	m_Orbit[3].TranslateZDelta(4.8f);
	
	this->AddPlacement(&m_Orbit[0]);
	this->AddPlacement(&m_Orbit[1]);
	this->AddPlacement(&m_Orbit[2]);
	this->AddPlacement(&m_Orbit[3]);
	/*
	m_DroneCarrier.AddPlacement(&m_Orbit[0]);
	m_DroneCarrier.AddPlacement(&m_Orbit[1]);
	m_DroneCarrier.AddPlacement(&m_Orbit[2]);
	m_DroneCarrier.AddPlacement(&m_Orbit[3]);
	*/

	int m_OrbitCounter = -1;
	float x[3] = { 4.65f, 3.8f, 2.7f };
	for (int c = 0; c < m_droneCount; c++)
	{
		if (c % (m_droneCount / 3) == 0)
		{
			m_OrbitCounter++;
		}
		m_pDock = new CDock;
		m_pDock->init(CHVector(x[m_OrbitCounter], 0.0f, 0.0f), (c)* (2 * PI / (m_droneCount / 3)), &m_Orbit[m_OrbitCounter]);
		m_Dock.push_back(m_pDock);
	}

	m_ShipHandler->register_Ship(this);

	this->AddPlacement(&m_DroneCarrier);
	m_Anzeigen.AddPlacement(&m_Rahmen);
	/*m_Anzeigen.AddPlacement(&m_LebensAnzeige);
	m_Anzeigen.AddPlacement(&m_LebensAnzeigeSchild);
	m_Anzeigen.AddPlacement(&m_LebensAnzeigeHintergrund);
	m_Anzeigen.AddPlacement(&m_LebensAnzeigeLeben);*/
	return true;
}
void CDroneCarrier::destroy_Ship()
{

}
void CDroneCarrier::work(float p_TimeDelta)
{
	m_Orbit[0].RotateZDelta(0.25f * p_TimeDelta);
	m_Orbit[1].RotateZDelta(-0.3f * p_TimeDelta);
	m_Orbit[2].RotateZDelta(0.4f * p_TimeDelta);
	
	if (moving)
	{		
		moving = m_Movement.arrive(m_MovementTarget, p_TimeDelta);
	}
	int m_OrbitCounter = -1;
	for (int c = 0; c < m_Dock.size(); c++)
	{
		if (m_Dock.at(c)->m_mode != 0)
		{
			CHMat mat = (m_Orbit->m_mLocal * this->m_mLocal );
			m_Dock.at(c)->work(p_TimeDelta, mat);
		}
	}
}

void CDroneCarrier::startDrones()
{
	for (CDock* Dock : m_Dock)
	{
		Dock->m_FightDrone.setMovementTarget(m_AttackTarget->GetTranslation());
		Dock->launch();
	}
}
void CDroneCarrier::callDronesBack()
{
	for (CDock* Dock : m_Dock)
	{
		Dock->m_FightDrone.setMovementTarget(m_AttackTarget->GetTranslation());
		Dock->home();
	}
}

CGeo* CDroneCarrier::getGeo(int i)
{
	switch (i)
	{
	case 0:
		return m_geoBase;
	case 1:
		return m_geoFront;
	case 2:
		return m_geoMiddle;
	case 3:
		return m_geoRear;
	}
	
}


int CDroneCarrier::getAnzBauteile()
{
	return m_iBauteileAnz;
}

void CDroneCarrier::AnzeigeOff()
{
	this->SubPlacement(&m_Anzeigen);
	/*
	this->SubPlacement(&m_Rahmen);
	this->SubPlacement(&m_LebensAnzeige);
	this->SubPlacement(&m_LebensAnzeigeHintergrund);
	this->SubPlacement(&m_LebensAnzeigeLeben);
	this->SubPlacement(&m_LebensAnzeigeSchild);
	*/
}

void CDroneCarrier::AnzeigeOn()
{
	this->AddPlacement(&m_Anzeigen);
	/*
	this->AddPlacement(&m_Rahmen);
	this->AddPlacement(&m_LebensAnzeige);
	this->AddPlacement(&m_LebensAnzeigeHintergrund);
	this->AddPlacement(&m_LebensAnzeigeLeben);
	this->AddPlacement(&m_LebensAnzeigeSchild);
	*/
}