#pragma once
#include "Projectile.h"
#include "Vektoria\Root.h"
class CProjectileHandler
{
public:
	static CProjectileHandler& instance()
	{
		static CProjectileHandler *instance = new CProjectileHandler();
		return *instance;
	}

	std::vector <CProjectile*> m_Projectile;

	void register_Projectile(CProjectile *p_Projectile);
	void deregister_Projectile(CProjectile *p_Projectile);
	void work(float p_TimeDelta);

	CScene *m_Scene;
	void Init(CScene *p_Scene);

private:
	CProjectileHandler();
	~CProjectileHandler();
};

