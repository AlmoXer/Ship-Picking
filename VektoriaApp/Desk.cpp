#include "Desk.h"


CDesk::CDesk()
{
}


CDesk::~CDesk()
{
}

bool CDesk::Init()
{
	m_GeoLoader = &m_GeoLoader->instance();

	m_pGeo = m_GeoLoader->getDesk();
	m_MaterialLoader = &m_MaterialLoader->instance();
	m_Material = *m_MaterialLoader->getDesk();

	m_pGeo->SetMaterial(&m_Material);
	this->AddGeo(m_pGeo);

	Name = "Desk";
	return true;
}