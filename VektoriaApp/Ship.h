#pragma once
#include "Selectable.h"
#include "Movement.h"
#include "Selectable.h"

class CShip :public CSelectable
{
public:
	CMovement m_Movement;
	CHVector m_MovementTarget;

	int m_Hull;
	int m_Shield;
	int m_ShieldRecovery;

	int anz;

	bool moving;

	virtual void destroy_Ship() = 0;
	virtual void work(float p_TimeDelta) = 0;

	virtual void setMovementTarget(CHVector p_Vector);
	virtual void removeMovementTarget();

	virtual void takeDamage(int p_Damage);

	virtual CGeo* getGeo(int i);

	virtual int getAnzBauteile();

	virtual void AnzeigeOn();
	virtual void AnzeigeOff();

	CShip();
	~CShip();
};

