#pragma once
#include "Selectable.h"
#include "Ship.h"
class CExtension :
	public CSelectable
{
public:
	CShip *m_Ship;

	CShip* getShip();
	void init(CShip*p_Ship, std::string p_Name);
	CExtension();
	~CExtension();
};

