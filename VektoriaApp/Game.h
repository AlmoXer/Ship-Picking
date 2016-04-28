#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#pragma comment (lib, "ApiUtils_Debug64.lib")
#pragma comment (lib, "ApiNullRenderer_Debug64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug64.lib")
#pragma comment (lib, "ApiDirectInput08_Debug64.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug64.lib")
#pragma comment (lib, "ApiOpenGL40_Debug64.lib")
#pragma comment (lib, "ApiNullSound_Debug64.lib")
#pragma comment (lib, "ApiDirectSound_Debug64.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#pragma comment (lib, "ApiUtils_Release64.lib")
#pragma comment (lib, "ApiNullRenderer_Release64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release64.lib")
#pragma comment (lib, "ApiDirectInput08_Release64.lib")
#pragma comment (lib, "ApiDirectX11FP_Release64.lib")
#pragma comment (lib, "ApiOpenGL40_Release64.lib")
#pragma comment (lib, "ApiNullSound_Release64.lib")
#pragma comment (lib, "ApiDirectSound_Release64.lib")
#pragma comment (lib, "ApiRenderDistributed_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#pragma comment (lib, "ApiUtils_Debug.lib")
#pragma comment (lib, "ApiNullRenderer_Debug.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug.lib")
#pragma comment (lib, "ApiDirectInput08_Debug.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug.lib")
#pragma comment (lib, "ApiOpenGL40_Debug.lib")
#pragma comment (lib, "ApiNullSound_Debug.lib")
#pragma comment (lib, "ApiDirectSound_Debug.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#pragma comment (lib, "ApiUtils_Release.lib")
#pragma comment (lib, "ApiNullRenderer_Release.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release.lib")
#pragma comment (lib, "ApiDirectInput08_Release.lib")
#pragma comment (lib, "ApiDirectX11FP_Release.lib")
#pragma comment (lib, "ApiOpenGL40_Release.lib")
#pragma comment (lib, "ApiNullSound_Release.lib")
#pragma comment (lib, "ApiDirectSound_Release.lib")
#pragma comment (lib, "ApiRenderDistributed_Release.lib")
#endif
#endif

#include "Vektoria\Root.h"
#include "GeoLoader.h"
#include "EnvironmentLoader.h"
#include "ShipHandler.h"
#include "ShipBuilder.h"
#include "GameMaster.h"
#include "ProjectileHandler.h"
#include "stdio.h"


using namespace Vektoria;

class CGame
{
public:
	//Base
	CRoot m_Root;
	CScene m_Scene;
	CFrame m_Frame;
	CViewport m_Viewport;
	//Handler
	CProjectileHandler *m_pProjectileHandler;
	CShipHandler *m_ShipHandler;

	//Loader
	CGeoLoader *m_GeoLoader;
	CMaterialLoader *m_MaterialLoader;

	//Camera
	CCamera m_Camera;
	CPlacement m_PCamera;

	//Lights
	CLightParallel m_LParallel;

	//Environment
	CEnvironmentLoader m_EnvironmentLoader;

	//Game Master
	CGameMaster m_GameMaster;

	//skybox
	CGeoSkybox m_GSkyBox;
	CPlacement m_PSkyBox;
	CMaterial m_MSkyBox;

	CSplash *m_Splash;

	//Devices
	CDeviceCursor m_DCursor;
	CDeviceKeyboard m_DKeyboard;
	CDeviceMouse m_DMouse;

	//ShipBuilder
	CShipBuilder m_ShipBuilder;

	//Timer 
	float m_timerRechts;
	float m_timerLinks;
	float m_timerMiddle;
	float m_timerKeyboard;

	CGame(void);																				
	~CGame(void);																				

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	
	void Tick(float fTime, float fTimeDelta);												
	void Fini();																				

	void WindowReSize(int iNewWidth, int iNewHeight);											
};


