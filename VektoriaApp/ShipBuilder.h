#pragma once
#include "TestShip.h"
#include "FightDrone.h"
#include "Vektoria\Root.h"
#include "DroneCarrier.h"
#include "Player.h"

class CShipBuilder
{
public:

	void Init();
	void Build(int p_Ship, Vektoria::CHVector p_Position, CPlayer *p_Player);

	CShip *Ship;
	CTestShip *TestShip;
	CDroneCarrier *DroneCarrier;

	CShipBuilder();
	~CShipBuilder();
};

