#include "Weapon.h"


CWeapon::CWeapon()
{
}


CWeapon::~CWeapon()
{
}

CShip* CWeapon::getShip()
{
	return m_Home;
}