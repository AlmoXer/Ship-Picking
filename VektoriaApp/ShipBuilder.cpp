#include "ShipBuilder.h"


CShipBuilder::CShipBuilder()
{
}


CShipBuilder::~CShipBuilder()
{
}

void CShipBuilder::Init()
{
}

void CShipBuilder::Build(int p_Ship, Vektoria::CHVector p_Position, CPlayer *p_Player)
{
	switch (p_Ship)
	{
	case 1: //Es wird ein Testship gebaut
		TestShip = new CTestShip();
		TestShip->Init(p_Player, p_Position);
		break;

	case 2: //Es wird eine DroneCarrier gebaut
		DroneCarrier = new CDroneCarrier();
		DroneCarrier->Init(p_Player, p_Position);
		break;

	default:
		break;
	}

}