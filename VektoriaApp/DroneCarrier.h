#pragma once
#include "BattleShip.h"
#include "ShipHandler.h"
#include "Dock.h"
#include "Extension.h"

class CDroneCarrier : public CBattleShip
{
public:
	CDroneCarrier();
	~CDroneCarrier();
	CShipHandler *m_ShipHandler;
	int m_droneCount;
	int m_iBauteileAnz;
	CDock *m_pDock;
	std::vector<CDock*> m_Dock;

	CGeo * m_geoBase;
	CGeo * m_geoFront;
	CGeo * m_geoMiddle;
	CGeo * m_geoRear;

	CPlacement m_Rahmen;
	CPlacement m_LebensAnzeige;
	CPlacement m_LebensAnzeigeHintergrund;
	CPlacement m_LebensAnzeigeSchild;
	CPlacement m_LebensAnzeigeLeben;

	CPlacement m_DroneCarrier;
	CPlacement m_Anzeigen;
	


	bool Init(CPlayer *p_Player, Vektoria::CHVector p_Position);
	void destroy_Ship();
	void work(float p_TimeDelta);

	void AnzeigeOn();
	void AnzeigeOff();

	void startDrones();
	void callDronesBack();
	CGeo* getGeo(int i);
	CPlacement* getPlacement();
	CExtension m_Orbit[4];

	int getAnzBauteile();
};

