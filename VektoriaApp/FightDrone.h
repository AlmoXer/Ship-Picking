#pragma once
#include "BattleShip.h"
#include "ShipHandler.h"
#include "TestLaser.h"
class CDock;

class CFightDrone : public CBattleShip
{
public:
	CFightDrone();
	~CFightDrone();

	CShipHandler *m_ShipHandler;
	CDock *m_Home;

	CTestLaser m_Laser;

	bool Init(CPlayer *p_Player);
	void work(float p_TimeDelta);
	void destroy_Ship();

	void goHome();
};