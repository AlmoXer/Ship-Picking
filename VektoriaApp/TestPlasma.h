#pragma once
#include "ProjectileHandler.h"
#include "ShipHandler.h"

class CShip;

class CTestPlasma : public CProjectile
{
public:
	CTestPlasma();
	~CTestPlasma();
	CShip *m_Ship;

	void Init(CShip *p_Ship, CHVector p_Position, CHVector p_Direction);

	CRay m_Ray;
	CShipHandler *m_ShipHandler;

	float m_timer;
	CProjectileHandler *m_ProjectileHandler;

	void work(float fTimeDelta);
};
