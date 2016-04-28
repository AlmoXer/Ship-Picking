#include "ShipHandler.h"


CShipHandler::CShipHandler()
{
}


CShipHandler::~CShipHandler()
{
}

void CShipHandler::Init(CScene *p_Scene)
{
	m_Scene = p_Scene;
	m_DebugHelper = m_DebugHelper->instance();
}

bool CShipHandler::register_Ship(CShip *p_Ship)
{
	m_Ships.push_back(p_Ship);
	m_Scene->AddPlacement(p_Ship);
	int sum = m_Ships.size();
	m_DebugHelper->write(sum);
	return true;
}

void CShipHandler::work(float p_TimeDelta)
{
	for (int x = 0; x < m_Ships.size(); x++)
	{
		m_Ships[x]->work(p_TimeDelta);
	}
}

bool CShipHandler::deregister_Ship(CShip *p_Ship)
{
	for (int x = 0; x < m_Ships.size(); x++)
	{
		if (m_Ships[x] == p_Ship)
		{
			m_Scene->SubPlacement(p_Ship);
			m_Ships.erase(m_Ships.begin() + x);
			int sum = m_Ships.size();
			m_DebugHelper->write(sum);
			return true;
		}
	}
	return false;
}