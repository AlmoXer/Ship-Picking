#pragma once
#include "Vektoria\Root.h"
#include "Desk.h"

class CEnvironmentLoader
{
public:
	CDesk m_Desk;

	void Init(CScene *p_Scene);

	CEnvironmentLoader();
	~CEnvironmentLoader();
};

