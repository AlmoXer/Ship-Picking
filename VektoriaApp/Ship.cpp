#include "Ship.h"


CShip::CShip()
{
}


CShip::~CShip()
{
}

void CShip::setMovementTarget(CHVector p_Vector)
{
	m_MovementTarget = p_Vector;
	moving = true;
}

void CShip::removeMovementTarget()
{
	m_MovementTarget = CHVector(0.0f,0.0f,0.0f,0.0f);
	moving = false;
}

void CShip::takeDamage(int p_damage)
{
	m_Hull -= p_damage;
	if (m_Hull <= 0)
	{
		this->destroy_Ship();
	}
}

CGeo* CShip::getGeo(int i)
{
	return &this->m_Geo;
}


int CShip::getAnzBauteile()
{
	return anz;
}

void CShip::AnzeigeOff()
{}

void CShip::AnzeigeOn()
{}
