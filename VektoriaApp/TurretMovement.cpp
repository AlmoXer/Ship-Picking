#include "TurretMovement.h"


CTurretMovement::CTurretMovement()
{
}


CTurretMovement::~CTurretMovement()
{
}

void CTurretMovement::Init(CLaser *p_Laser, Vektoria::CHVector p_Orientation)
{
	m_Laser = p_Laser;

	StartRotation = p_Laser->m_mLocal;
	Startdirection = p_Orientation;
	time = 0.0;
	distance = 0;
	absolutRotation = 0.0f;
	relativeRotation = 0.0f;
}

bool CTurretMovement::moveToTarget(float p_TimeDelta, CPlacement *p_Target)
{
	time += p_TimeDelta;
	current_position_to_Ship = m_Laser->GetTranslation();
	current_position = m_Laser->m_Home->GetTranslation() + current_position_to_Ship;
	direction = p_Target->GetTranslation() - current_position;
	distance = direction.Length();

	if (distance <= m_Laser->Range)
	{

		angleZ = atan2(m_Laser->m_Home->m_mLocal.m_fx10, m_Laser->m_Home->m_mLocal.m_fx00);
		axis_of_rotation = direction ^ (Startdirection);
		rotation_angle = acos((direction*(Startdirection) / (direction.Length() * Startdirection.Length())));

		if (axis_of_rotation.GetZ() >= 0)
			rotation_angle *= (-1.0f);

		if (rotation_angle >= m_Laser->openClock && rotation_angle <= m_Laser->openCounterClock)
		{
			absolutRotation = rotation_angle - angleZ;
			Ergebnis = time * m_Laser->maxRotationSpeed;

			if (relativeRotation >= (absolutRotation + 0.05) || relativeRotation < (absolutRotation - 0.05))
			{

				if (rotation_angle <= 0)
					relativeRotation -= Ergebnis;
				else
					relativeRotation += Ergebnis;

				m_Laser->m_mLocal = StartRotation;
				m_Laser->TranslateDelta(-current_position_to_Ship.GetX(), -current_position_to_Ship.GetY(), -current_position_to_Ship.GetZ());
				m_Laser->RotateZDelta(relativeRotation);
				m_Laser->TranslateDelta(current_position_to_Ship);
			}
			else
			{
				return true;
			}

		}
	}
	time = 0;
	return false;
}