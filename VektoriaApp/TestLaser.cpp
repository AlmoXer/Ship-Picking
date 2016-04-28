#include "TestLaser.h"


CTestLaser::CTestLaser()
{
}


CTestLaser::~CTestLaser()
{
}

void CTestLaser::Init(CHVector p_Position, CHVector p_Orientation, CShip *p_Ship, float p_open_clock, float p_open_counterclock)
{
	Name = "TestLaser";
	m_GeoLoader = &m_GeoLoader->instance();
	this->AddGeo(m_GeoLoader->getLaser());

	this->TranslateDelta(p_Position);
	m_Home = p_Ship;

	openClock = p_open_clock;
	openCounterClock = p_open_counterclock;
	maxRotationSpeed = 0.70f;
	Range = 100;
	cooldown = 1.5f;
	AttackTimer = 0.0f;
	m_TurretMovement.Init(this, p_Orientation);

}

bool CTestLaser::destroy(float p_TimeDelta, CPlacement *p_Target)
{
	AttackTimer += p_TimeDelta;
	m_Target = p_Target;

	if (m_TurretMovement.moveToTarget(p_TimeDelta, p_Target) && (AttackTimer >= cooldown))
	{
		AttackTimer = 0;
		m_TestPlasma = new CTestPlasma;
		m_TestPlasma->Init(m_Home, (m_Home->GetTranslation() + this->GetTranslation()), m_TurretMovement.direction);
	}
	return false;
}