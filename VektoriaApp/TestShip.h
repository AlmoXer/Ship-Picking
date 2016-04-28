#pragma once
#include "BattleShip.h"
#include <string.h>
#include "TestLaser.h"
#include "ShipHandler.h"

class CTestShip : public CBattleShip
{
public:
	CWribel m_wAnzeige;
	CWritingFont m_wfAnzeige;
	CPlacement m_LebensAnzeige;

	int m_iBauteileAnz;

	CShipHandler *m_ShipHandler;
	CGeo* geo;

	bool Init(CPlayer *p_Player, Vektoria::CHVector p_Position);
	void destroy_Ship();
	void work(float p_TimeDelta);
	CWribel * getWribel();
	CGeo *getGeo(int k);
	CTestLaser m_LaserRight;
	CTestLaser m_LaserLeft;
	int getAnzBauteile();

	void AnzeigeOff();
	void AnzeigeOn();

	CTestShip();
	~CTestShip();
};

