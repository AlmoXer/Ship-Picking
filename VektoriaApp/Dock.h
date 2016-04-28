#pragma once
#include "FightDrone.h"
#include "Element.h"
#include "Player.h"
#include "ShipHandler.h"

class CDock : public CElement
{
public:
	CFightDrone *m_FightingDrone;
	CShipHandler *m_ShipHandler;
	CHMat m_FighterMat;

	bool m_outdoors;
	bool m_occupied;
	bool m_other;
	int m_mode;

	float m_startX, m_currentX;
	float m_speed;
	float m_rotation;

	void setMovementTarget();
	void setAttackTarget();

	void home();
	void launch();
	void work(float p_timeDelta, CHMat);

	void init(CHVector p_Position, float p_Rotation, CPlacement *p_Parent);


	CDock();
	~CDock();

	CFightDrone m_FightDrone;
};

