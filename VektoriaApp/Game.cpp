#include "StdAfx.h"
#include "Game.h"
#include "Connection.h"
#include "MoveAction.h"
class CMoveAction;

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	//Base
	m_Root.Init(psplash);
	m_Frame.Init(hwnd, procOS, eApiRender_DirectX11_Shadermodel50_Standard, eApiInput_DirectInput, eApiSound_DirectSound, eShaderCreation_UseCached, eShaderAutoRecompilation_Disabled);
	m_Viewport.InitFull(&m_Camera);
	m_Scene.Init();
//	m_Viewport.SetWireframeOn();

	//Handler
	m_pProjectileHandler = &m_pProjectileHandler->instance();
	m_pProjectileHandler->Init(&m_Scene);
	m_ShipHandler = &m_ShipHandler->instance();
	m_ShipHandler->Init(&m_Scene);

	//Loader
	m_MaterialLoader = &m_MaterialLoader->instance();
	m_MaterialLoader->Init();

	//Materialen Laden
	m_Root.AddMaterial(m_MaterialLoader->getRahmenDroneCarrier());
	m_Root.AddMaterial(m_MaterialLoader->getRahmenTestShip());
	m_Root.AddMaterial(m_MaterialLoader->getDesk());
	m_Root.AddMaterial(m_MaterialLoader->getPlasma());
	m_Root.AddMaterial(m_MaterialLoader->getLebensAnzeige());
	m_Root.AddMaterial(m_MaterialLoader->getLebensAnzeigeHintergrund());
	m_Root.AddMaterial(m_MaterialLoader->getLebensAnzeigeSchild());
	m_Root.AddMaterial(m_MaterialLoader->getLebensAnzeigeLeben());


	m_GeoLoader = &m_GeoLoader->instance();
	m_GeoLoader->Init();

	m_Scene.SetLightAmbient(0.2f);

	//Loader
	m_EnvironmentLoader.Init(&m_Scene);

	//Camera
	m_Camera.Init();
	m_PCamera.AddCamera(&m_Camera);

	//Lights
	m_LParallel.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));

	//SkyBox
	m_GSkyBox.Init(CHVector(1000.0f, 1000.0f, 1000.0f), &m_MSkyBox, &m_LParallel);
	m_PSkyBox.AddGeo(&m_GSkyBox);
	m_MSkyBox.MakeTextureDiffuse("textures\\Black.png");

	// Hierarchy Tree
	m_Root.AddFrame(&m_Frame);
	m_Root.AddScene(&m_Scene);

	m_Frame.AddViewport(&m_Viewport);
	m_Frame.AddDeviceKeyboard(&m_DKeyboard);
	m_Frame.AddDeviceMouse(&m_DMouse);
	m_Frame.AddDeviceCursor(&m_DCursor);

	m_Scene.AddPlacement(&m_PCamera);
	m_Scene.AddLightParallel(&m_LParallel);
	m_Scene.AddPlacement(&m_PSkyBox);

	//Ships
	m_ShipBuilder.Init();

	//Stuff goes Places
	m_PCamera.Translate(0.0f, 0.0f, 15.0f);

	//Timer goes Null
	m_timerRechts = 0.0f;
	m_timerLinks = 0.0f;
	m_timerKeyboard = 0.0f;
	m_timerMiddle = 0.0f;

	//GameMaster
	m_GameMaster.Init(&m_DCursor, &m_DKeyboard, &m_DMouse, &m_ShipBuilder);

	//TODO Remove Testcode
	//Initialize Sockets
	InitSockets(); // returns false if init unsuccessful

	Net::CConnection connection;
	connection.SetListenPort(12345);
	Net::CAddress client;//defaults to localhost
	client.SetPOrt(12345);
	connection.SetClientAddress(client);

	connection.StartListening();

	CMoveAction mac;

	mac.Add(10,11,12);
	mac.Add(20, 21, 22);

	connection.Send(*mac.BuildPacket());
	connection.ProcessRecieved();
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	m_Root.Tick(fTimeDelta);

	//Linke Mustaste wird gedrückt
	if (m_DMouse.ButtonPressedLeft() && m_timerLinks < 0.0f)
	{
		m_timerLinks = 0.2f;
		m_GameMaster.ButtonPressedLeft();
	}
	//Rechte Maustaste gedrückt
	if (m_DMouse.ButtonPressedRight())
	{				
		
		m_PCamera.TranslateDelta(-m_DMouse.GetRelativeX() * 50, -m_DMouse.GetRelativeY() * 50, 0);
		if (m_timerRechts < 0.0f)
		{
			m_timerRechts = 0.2f;
			m_GameMaster.ButtonPressedRight();
		}

	}
	//Mittlere Maustaste wird gedrückt
	if (m_DMouse.ButtonPressedMid() && m_timerMiddle < 0)
	{
		m_timerMiddle = 0.2f;
		m_GameMaster.ButtonBresseMid();
	}
	//Eine Taste wird gedrückt
	if (m_DKeyboard.GetKey() && m_timerKeyboard < 0)
	{
		m_timerKeyboard = 0.2f;
		m_GameMaster.KeyPressed(m_DKeyboard.GetKey());
	}

	//Mausrad liefert einen wert
	if (m_DMouse.GetRelativeZ() != 0)
	{
		m_PCamera.TranslateZDelta(-m_DMouse.GetRelativeZ() * 5);
	}


	m_ShipHandler->work(fTimeDelta);
	m_pProjectileHandler->work(fTimeDelta);

	//Timer
	m_timerRechts -= fTimeDelta;
	m_timerLinks -= fTimeDelta;
	m_timerMiddle -= fTimeDelta;
	m_timerKeyboard -= fTimeDelta;
}

void CGame::Fini()
{

}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	m_Frame.ReSize(iNewWidth, iNewHeight);
	m_Viewport.ReSize();
}

