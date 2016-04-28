#include "TestPlasma.h"


CTestPlasma::CTestPlasma()
{
}


CTestPlasma::~CTestPlasma()
{
}

void CTestPlasma::work(float fTimeDelta)
{
	m_timer -= fTimeDelta;
	m_Direction.Norm();
	this->TranslateDelta(m_Direction *fTimeDelta * 4);

	if (m_timer <= 0)
	{
		m_ProjectileHandler->deregister_Projectile(this);
		delete(this);
		return;
	}

	CAABB *testing2 = GetAABB();
	if (testing2 != nullptr)
	{
		for (int x = 0; x < m_ShipHandler->m_Ships.size(); x++)
		{
			CAABB *testing = m_ShipHandler->m_Ships[x]->GetAABB();
			if (m_Ship != m_ShipHandler->m_Ships[x] && testing->Intersects(*testing2))
			{
				m_ShipHandler->m_Ships[x]->takeDamage(10);
				m_ProjectileHandler->deregister_Projectile(this);
				delete(this);
				return;
			}
		}
	}
}

void CTestPlasma::Init(CShip *p_Ship, CHVector p_Position, CHVector p_Direction)
{
	m_timer = 10.0f;
	m_GeoLoader = &m_GeoLoader->instance();
	m_Direction = p_Direction;
	m_Position = p_Position;
	this->TranslateDelta(p_Position);
	this->AddGeo(m_GeoLoader->getPlasma());
	this->EnableAABBs();
	CAABB *m_Fuckit = this->m_aaabb;
	m_ProjectileHandler = &m_ProjectileHandler->instance();
	m_ProjectileHandler->register_Projectile(this);

	m_Ship = p_Ship;
	m_ShipHandler = &m_ShipHandler->instance();
}