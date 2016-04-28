#include "GameMaster.h"


CGameMaster::CGameMaster()
{
}

CGameMaster::~CGameMaster()
{
}

void CGameMaster::Init(CDeviceCursor *p_DCursor, CDeviceKeyboard *p_DKeyboard, CDeviceMouse *p_DMouse, CShipBuilder *p_ShipBuilder)
{
	EtwasGepickt = false;
	m_DCursor = p_DCursor;
	m_DKeyboard = p_DKeyboard;
	m_DMouse = p_DMouse;
	m_ShipBuilder = p_ShipBuilder;


	m_HRightMouse = nullptr;

	m_PLeftMouse = nullptr;
	m_SMemoryLeft = nullptr;

	m_PMiddle = nullptr;
	m_SMemoryMiddle = nullptr;

	m_Weapon = nullptr;
	m_ShipHandler = &m_ShipHandler->instance();
	m_DebugHelper = m_DebugHelper->instance();
	m_DebugHelper->Init();
	//Adden von playern
	this->addPlayer();
	this->addPlayer();

	//Hinzufügen von Schiffen unterschiedlicher Spieler
	m_ShipBuilder->Build(1, CHVector(0.0f, 30.0f, 0.0f), m_VPlayer[0]);
	m_ShipBuilder->Build(2, CHVector(0.0f, 0.0f, 0.0f), m_VPlayer[1]);
	//m_ShipBuilder->Build(2, CHVector(0.0f, 15.0f, 0.0f), m_VPlayer[1]);
}

void CGameMaster::ButtonPressedLeft()
{
	EtwasGepickt = false;
	CGeos geos;
	CShip * ship;
	std::vector<CShip*>::iterator Iterator;


	//Alle vorhandenen Geos werden geladen
	for (Iterator = m_ShipHandler->m_Ships.begin(); Iterator != m_ShipHandler->m_Ships.end(); ++Iterator)
	{
		ship = *Iterator._Ptr;
		for (int k = 0; k < ship->getAnzBauteile(); k++)
		{
			geos.Add(ship->getGeo(k));
		}
	}

	CGeo*  pgeo = m_DCursor->PickGeoPreselected(geos);
		
	if (pgeo != nullptr)
	{

		m_Selectable = dynamic_cast<CSelectable*> (pgeo->m_nodesParents.m_apnode[0]);
		if (m_Selectable != nullptr)
		{
			m_DebugHelper->write(m_Selectable->getName());

			m_Weapon = dynamic_cast<CWeapon*> (pgeo->m_nodesParents.m_apnode[0]);
			if (m_Weapon != nullptr)
			{
				m_SMemoryLeft = m_Weapon->getShip();
				m_DebugHelper->write(m_SMemoryLeft->getName());
				return;
			}
			m_Extension = dynamic_cast<CExtension*> (pgeo->m_nodesParents.m_apnode[0]);
			if (m_Extension != nullptr)
			{
				m_SMemoryLeft = m_Extension->getShip();
				m_DebugHelper->write(m_SMemoryLeft->getName());
				return;
			}
			m_Ship = dynamic_cast<CShip*> (pgeo->m_nodesParents.m_apnode[0]);
			if (m_Ship != nullptr)
			{
				//Stimmt eine Gepickte Geo mit den vorhandenen überein
				for (Iterator = m_ShipHandler->m_Ships.begin(); Iterator != m_ShipHandler->m_Ships.end(); ++Iterator)
				{
					ship = *Iterator._Ptr;

					for (int k = 0; k <= ship->getAnzBauteile(); k++)
					{
						if (pgeo == ship->getGeo(k))
						{
							if (m_SelectedShips.size() != 0)
							{
								//Wenn LShift gedrückt wird überspringt er die Entselektierung
								if (!m_DKeyboard->KeyPressed(DIK_LSHIFT))
								{
									CShip* ShipHelp;
									std::vector<CShip*>::iterator Iterator1;
									for (Iterator1 = m_ShipHandler->m_Ships.begin(); Iterator1 != m_ShipHandler->m_Ships.end(); ++Iterator1)
									{
										ShipHelp = *Iterator1._Ptr;
										ShipHelp->AnzeigeOff();
									}
									this->SubShips();
								}

							}
							EtwasGepickt = true;
							m_SMemoryLeft = ship;
							ship->AnzeigeOn();
							this->addShip(ship);
						}
					}
				}
			}
		}
	}
	


	// Falls keine Geo getroffen wurde die zu einem Objekt gehört -> Entselektierung
	if (EtwasGepickt == false)
	{
		CShip* ShipHelp;
		std::vector<CShip*>::iterator Iterator1;
		for (Iterator1 = m_SelectedShips.begin(); Iterator1 != m_SelectedShips.end(); ++Iterator1)
		{
			ShipHelp = *Iterator1._Ptr;
			ShipHelp->AnzeigeOff();
		}
		m_SMemoryLeft = nullptr;
		this->SubShips();
	}
	
}

void CGameMaster::ButtonPressedRight()
{
	m_HRightMouse = m_DCursor->PickHitPoint();

	if (m_HRightMouse != nullptr)
		m_DebugHelper->writeHitPoint(m_HRightMouse->m_vPos.GetX(), m_HRightMouse->m_vPos.GetY(), m_HRightMouse->m_vPos.GetZ());

	m_SMemoryLeft = dynamic_cast<CShip*> (m_SMemoryLeft);
	if (m_SMemoryLeft != nullptr && m_HRightMouse != nullptr)
	{
		//Rechtsklick wen mit der Linken vorher ein Ship angewählt wurde.
		m_SMemoryLeft->setMovementTarget(m_HRightMouse->m_vPos);
	}
}

void CGameMaster::ButtonBresseMid()
{
	m_PMiddle = m_DCursor->PickPlacement();
	m_Weapon = dynamic_cast<CWeapon*> (m_PMiddle);
	if (m_Weapon != nullptr)
	{
		m_SMemoryMiddle = m_Weapon->getShip();


		m_BattleShip = dynamic_cast<CBattleShip*> (m_SMemoryLeft);
		if (m_BattleShip != nullptr)
		{
			m_BattleShip->setAttackTarget(m_SMemoryMiddle);
			m_DebugHelper->write("ATTACK TARGET" + m_SMemoryMiddle->getName());
		}

		m_DroneCarrier = dynamic_cast<CDroneCarrier*> (m_SMemoryLeft);
		if (m_DroneCarrier != nullptr)
		{

		}
	}
}

void CGameMaster::KeyPressed(int p_Key)
{
	m_DebugHelper->write(p_Key);
	switch (p_Key)
	{
	case 2:
		m_DroneCarrier = dynamic_cast<CDroneCarrier*> (m_SMemoryLeft);
		if (m_DroneCarrier != nullptr && m_DroneCarrier->m_AttackTarget != nullptr)
		{
			m_DebugHelper->write("Drones Start");
			m_DroneCarrier->startDrones();
		}
		break;
	case 3:
		m_DroneCarrier = dynamic_cast<CDroneCarrier*> (m_SMemoryLeft);
		if (m_DroneCarrier != nullptr && m_DroneCarrier->m_AttackTarget != nullptr)
		{
			m_DebugHelper->write("Drones Back Home");
			m_DroneCarrier->callDronesBack();
		}
		break;
	}
}


void CGameMaster::addPlayer()
{
	m_pPlayer = new CPlayer;
	m_VPlayer.push_back(m_pPlayer);
}

void CGameMaster::addShip(CShip * m_pShip)
{
	m_SelectedShips.push_back(m_pShip);
}

void CGameMaster::SubShips()
{
	m_SelectedShips.clear();
}