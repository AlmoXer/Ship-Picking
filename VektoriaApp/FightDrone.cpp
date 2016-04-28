#include "FightDrone.h"


CFightDrone::CFightDrone()
{
}


CFightDrone::~CFightDrone()
{
}

bool CFightDrone::Init(CPlayer *p_Player)
{
	m_GeoLoader = &m_GeoLoader->instance();
	this->AddGeo(m_GeoLoader->getFightDrone());

	m_Hull = 20;
	m_Shield = 10;
	m_ShieldRecovery = 1;

	m_IDDistributor = &m_IDDistributor->instance();
	ID = m_IDDistributor->getID(1, 1, 11, p_Player->m_number);
	m_Player = p_Player;
	Name = "FightDrone";

	m_MovementTarget = this->GetTranslation();
	m_Movement.init(this);

	this->RotateXDelta(-HALFPI);
	this->RotateYDelta(-HALFPI);

	m_Laser.Init(CHVector(0.0f, 0.0f, -4.0f), CHVector(1.0f, 0.0f, 0.0f), this, 0, PI);

	//this->AddPlacement(&m_Laser);

	m_ShipHandler = &m_ShipHandler->instance();
	return true;
}

void CFightDrone::destroy_Ship()
{

}

void CFightDrone::work(float p_TimeDelta)
{
	m_Movement.arriveDrone(m_MovementTarget, p_TimeDelta);
}