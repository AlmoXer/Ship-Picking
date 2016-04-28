#include "EnvironmentLoader.h"


CEnvironmentLoader::CEnvironmentLoader()
{
}


CEnvironmentLoader::~CEnvironmentLoader()
{
}

void CEnvironmentLoader::Init(CScene *p_Scene)
{
	//Desk
	m_Desk.Init();
	m_Desk.RotateXDelta(HALFPI);
	m_Desk.ScaleDelta(100);
	m_Desk.TranslateZDelta(-210);
	p_Scene->AddPlacement(&m_Desk);
}