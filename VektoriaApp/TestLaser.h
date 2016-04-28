#pragma once
#include "Laser.h"
#include "TestPlasma.h"
#include "TurretMovement.h"

class CTestLaser : public CLaser
{
public:
	CTestLaser();
	~CTestLaser();

	void Init(CHVector p_Position, CHVector p_Ausrichtung, CShip *p_Ship, float open_clock, float open_counterclock);
	bool destroy(float p_TimeDelta, CPlacement *p_Placement);
	
	CTestPlasma *m_TestPlasma;
	CTurretMovement m_TurretMovement;
};
