#include "ProjectileHandler.h"


CProjectileHandler::CProjectileHandler()
{
}


CProjectileHandler::~CProjectileHandler()
{
}

void CProjectileHandler::register_Projectile(CProjectile *p_Projectile)
{
	m_Projectile.push_back(p_Projectile);
	m_Scene->AddPlacement(p_Projectile);
}

void CProjectileHandler::deregister_Projectile(CProjectile *p_Projectile)
{
	for (int x = 0; x < m_Projectile.size(); x++)
	{
		if (m_Projectile[x] == p_Projectile)
		{
			m_Scene->SubPlacement(p_Projectile);
			m_Projectile.erase(m_Projectile.begin() + x);
		}
	}
}

void CProjectileHandler::work(float p_TimeDelta)
{
	for (int x = 0; x < m_Projectile.size(); x++)
	{
		m_Projectile[x]->work(p_TimeDelta);
	}
}

void CProjectileHandler::Init(CScene *p_Scene)
{
	m_Scene = p_Scene;
}