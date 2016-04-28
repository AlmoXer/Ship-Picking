#pragma once
#include "Vektoria\Root.h"
#include "Ship.h"
#include "Weapon.h"
#include "Player.h"
#include "ShipBuilder.h"
#include "DebugHelper.h"
#include "ShipHandler.h"
#include "BattleShip.h"
#include "DroneCarrier.h"

using namespace Vektoria;
class CGameMaster
{
public:

	CDeviceCursor *m_DCursor;
	CDeviceKeyboard *m_DKeyboard;
	CDeviceMouse *m_DMouse;

	bool EtwasGepickt;
	//Right Mouse
	CHitPoint *m_HRightMouse;

	//Left Mouse
	CPlacement *m_PLeftMouse;
	CShip *m_SMemoryLeft;


	//Middle Mouse
	CPlacement *m_PMiddle;
	CShip *m_SMemoryMiddle;

	CShip *m_Ship;
	CSelectable *m_Selectable;
	CBattleShip *m_BattleShip;
	CWeapon *m_Weapon;
	CExtension *m_Extension;
	CDroneCarrier *m_DroneCarrier;

	std::vector<CShip*> m_SelectedShips;


	std::vector<CPlayer*> m_VPlayer;
	CPlayer *m_pPlayer;

	CDebugHelper *m_DebugHelper;

	CShipBuilder *m_ShipBuilder;

	CShipHandler *m_ShipHandler;

	CGameMaster();
	~CGameMaster();
	void Init(CDeviceCursor *p_DCursor, CDeviceKeyboard *p_DKeyboard, CDeviceMouse *p_DMouse, CShipBuilder *p_ShipBuilder);

	//Mouse
	void ButtonPressedLeft();
	void ButtonPressedRight();
	void ButtonBresseMid();

	//Keyboard
	void KeyPressed(int p_Key);

	//Player Handling
	void addPlayer();

	//Selected Ship Handling
	void addShip(CShip * m_pShip);
	void SubShips();
};

