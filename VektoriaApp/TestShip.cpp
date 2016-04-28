#include "TestShip.h"


CTestShip::CTestShip()
{
}


CTestShip::~CTestShip()
{
}

bool CTestShip::Init(CPlayer *p_Player, Vektoria::CHVector p_Position)
{
	m_iBauteileAnz = 1;

	m_GeoLoader = &m_GeoLoader->instance();
	geo=m_GeoLoader->getShip();

	m_LebensAnzeige.AddGeo(m_GeoLoader->getRahmenTestShip());
	m_LebensAnzeige.SetBillboard();

	this->AddGeo(geo);
	this->TranslateDelta(p_Position);
	m_AttackTarget = nullptr;

	m_Hull = 100;
	m_Shield = 100;
	m_ShieldRecovery = 2;

	m_IDDistributor = &m_IDDistributor->instance();
	ID = m_IDDistributor->getID(1, 1, 11, p_Player->m_number);
	m_Player = p_Player;
	Name = "Testship";

	m_MovementTarget = this->GetTranslation();
	m_Movement.init(this);

	CHVector m_Speicher;
	m_Speicher = m_LaserRight.GetTranslation();
	m_LaserRight.TranslateDelta(-m_Speicher.GetX(), -m_Speicher.GetY(), -m_Speicher.GetZ());
	m_LaserRight.RotateYDelta(HALFPI);
	m_LaserRight.RotateXDelta(HALFPI);
	m_LaserRight.TranslateDelta(m_Speicher);

	m_Speicher = m_LaserLeft.GetTranslation();
	m_LaserLeft.TranslateDelta(-m_Speicher.GetX(), -m_Speicher.GetY(), -m_Speicher.GetZ());
	m_LaserLeft.RotateYDelta(HALFPI);
	m_LaserLeft.RotateXDelta(HALFPI);
	m_LaserLeft.TranslateDelta(m_Speicher);

	m_LaserRight.Init(CHVector(0.0f, 1.0f, 0.0f), CHVector(-1.0f, 0.0f, 0.0f), this,  -PI, 0.2);
	m_LaserLeft.Init(CHVector(0.0f, -1.0f, 0.0f), CHVector(-1.0f, 0.0f, 0.0f), this, -0.2, PI);

	this->AddPlacement(&m_LaserRight);
	this->AddPlacement(&m_LaserLeft);

	m_ShipHandler = &m_ShipHandler->instance();
	m_ShipHandler->register_Ship(this);
	return true;
}

void CTestShip::destroy_Ship()
{
	m_ShipHandler->deregister_Ship(this);
	delete(this);
}

void CTestShip::work(float p_TimeDelta)
{
	if (m_AttackTarget != nullptr)
	{
		m_LaserRight.destroy(p_TimeDelta, m_AttackTarget);
		m_LaserLeft.destroy(p_TimeDelta, m_AttackTarget);
	}
	m_Movement.arrive(m_MovementTarget, p_TimeDelta);
}

CGeo * CTestShip::getGeo(int k)
{
	return geo;
}


int CTestShip::getAnzBauteile()
{
	return m_iBauteileAnz;
}

void CTestShip::AnzeigeOff()
{
	this->SubPlacement(&m_LebensAnzeige);
}

void CTestShip::AnzeigeOn()
{
	this->AddPlacement(&m_LebensAnzeige);
}