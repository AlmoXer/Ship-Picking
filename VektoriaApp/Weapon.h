#pragma once
#include "Selectable.h"
#include "Vektoria\\Root.h"
#include "Ship.h"
#include "Movement.h"

using namespace Vektoria;


class CWeapon :	public CSelectable
{
public:
	CWeapon();
	~CWeapon();	

	CShip *m_Home;

	CShip* getShip();
};

