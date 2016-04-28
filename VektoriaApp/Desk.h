#pragma once
#include "EnvironmentObject.h"
class CDesk : public CEnvironmentObject
{
public:
	bool Init();

	CGeo *m_pGeo;

	CDesk();
	~CDesk();
};

