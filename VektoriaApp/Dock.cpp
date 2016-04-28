#include "Dock.h"


CDock::CDock()
{
}


CDock::~CDock()
{
}

void CDock::init(CHVector p_Position, float p_Rotation, CPlacement *p_Parent)
{
	this->Translate(p_Position);
	this->RotateZDelta(p_Rotation);
	m_startX = p_Position.GetX();
	m_currentX = m_startX;
	m_rotation = p_Rotation;
	Name = "Dock";

	CPlayer m_Player;
	m_FightDrone.Init(&m_Player);
	this->AddPlacement(&m_FightDrone);
	m_ShipHandler = &m_ShipHandler->instance();
	m_speed = 1;
	m_outdoors = false;
	p_Parent->AddPlacement(this);
	m_mode = 0;
}

void  CDock::launch()
{
	m_mode = 1;
}
void  CDock::home()
{
	m_mode = 2;
	m_other = true;
}

void  CDock::work(float p_timeDelta, CHMat p_Mat)
{
	switch (m_mode)
	{
	case 1:	//Launching the Fighter
		if (m_currentX < 1.5 * m_startX)
		{
			m_currentX += m_speed * p_timeDelta;
			this->Translate(m_currentX, 0.0f, 0.0f);
			this->RotateZDelta(m_rotation);
		}
		else if (!m_outdoors)
		{
			this->SubPlacement(&m_FightDrone);
			m_FighterMat = m_FightDrone.m_mLocal;
			m_FightDrone.m_mLocal = m_FightDrone.m_amGlobal[0];
			m_ShipHandler->register_Ship(&m_FightDrone);
			m_mode = 0;
			m_outdoors = true;
		}
		break;

	case 2: //home
		if (m_other && m_outdoors)
		{
			m_FightDrone.setMovementTarget(this->m_amGlobal[0].GetTranslation());
			float testing = (this->m_amGlobal[0].GetTranslation() - m_FightDrone.GetTranslation()).Length();
			if (testing < 3)
			{
				m_other = false;
				m_FightDrone.m_mLocal = m_FighterMat;
				this->AddPlacement(&m_FightDrone);
				m_ShipHandler->deregister_Ship(&m_FightDrone);
				m_outdoors = false;
			}

		}
		else
		{
			m_currentX -= m_speed * p_timeDelta;
			if (m_currentX <= m_startX)
			{
				m_currentX = m_startX;
				m_mode = 0;
			}
			this->Translate(m_currentX, 0.0f, 0.0f);
			this->RotateZDelta(m_rotation);
		}
		break;
	}
}


