#pragma once
#include "Ship.h"
#include "Vektoria\Root.h"
#include "DebugHelper.h"

class CShipHandler
{
public:
	static CShipHandler& instance()
	{
		static CShipHandler *instance = new CShipHandler();
		return *instance;
	}

	CDebugHelper *m_DebugHelper;

	CScene *m_Scene;
	std::vector <CShip*> m_Ships;

	bool register_Ship(CShip *p_Ship);
	bool deregister_Ship(CShip *p_Ship);
	void Init(CScene *p_Scene);

	void work(float p_TimeDelta);

private: 

	CShipHandler();
	~CShipHandler();
};

