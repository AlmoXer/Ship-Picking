#include "Movement.h"


CMovement::CMovement()
{
}


CMovement::~CMovement()
{
}

void CMovement::init(Vektoria::CPlacement *p_movingobject)
{
	object = p_movingobject;
	orientation = Vektoria::CHVector(-1.0, 0.0, 0.0);
	max_rotation_speed = 0.70;
	time = 0;
	executions_per_second = 60;
	max_movement_speed = 3;
	arive_radius = 2;

	//Winkel aus der Matrix berechnen.
	x = atan2(object->m_mLocal.m_fx21, object->m_mLocal.m_fx22);
	y = atan2(-object->m_mLocal.m_fx20, std::sqrt((object->m_mLocal.m_fx21 * object->m_mLocal.m_fx21) + (object->m_mLocal.m_fx22 * object->m_mLocal.m_fx22)));
	z = atan2(object->m_mLocal.m_fx00, object->m_mLocal.m_fx10);

}

bool CMovement::arrive(Vektoria::CHVector target, float timedelta)
{
	time += timedelta;
	if (time > (1 / executions_per_second))
	{
		current_position = object->GetTranslation();
		direction = target - current_position;
		direction.SetZ(0.0f);
		distance = direction.Length();

		if (distance >= arive_radius)
		{
			object->TranslateDelta(-current_position.GetX(), -current_position.GetY(), -current_position.GetZ());
			axis_of_rotation = direction ^ (orientation);
			rotation_angle = acos((direction * (orientation) / (direction.Length() * orientation.Length())));
			if (rotation_angle > 0.25 || rotation_angle < -0.25)
			{
				if (axis_of_rotation.GetZ() >= 0)
					rotation_angle *= (-1);

				rotation_angle_safe = rotation_angle;
				if (rotation_angle >(max_rotation_speed * time))
					rotation_angle = (max_rotation_speed * time);
				if (rotation_angle < -(max_rotation_speed * time))
					rotation_angle = -(max_rotation_speed * time);
				object->RotateZDelta(rotation_angle);

				orientation = Vektoria::CHVector(
					orientation.GetX()*cos(rotation_angle) + orientation.GetY()*(-sin(rotation_angle)),
					orientation.GetX()*sin(rotation_angle) + orientation.GetY()*(cos(rotation_angle)),
					0);
			}
			object->TranslateDelta(current_position);

			if (rotation_angle_safe <= 0.75 && rotation_angle_safe >= -0.75)
			{
				direction = (orientation * max_movement_speed *time);
				object->TranslateDelta(direction.GetX(), direction.GetY(), direction.GetZ());
			}

		}
		else
		{
			time = 0;
			return false;
		}
		time = 0;

		//Winkel aus der Matrix berechnen
		/*
		x = atan2(object->m_mLocal.m_fx21, object->m_mLocal.m_fx22);
		y = atan2(-object->m_mLocal.m_fx20, std::sqrt((object->m_mLocal.m_fx21 * object->m_mLocal.m_fx21) + (object->m_mLocal.m_fx22 * object->m_mLocal.m_fx22)));
		z = atan2(object->m_mLocal.m_fx00, object->m_mLocal.m_fx10);*/
	}
	return true;
}

bool CMovement::arriveDrone(Vektoria::CHVector target, float timedelta)
{
	time += timedelta;
	if (time > (1 / executions_per_second))
	{
		current_position = object->GetTranslation();
		direction = target - current_position;
		distance = direction.Length();

		if (distance >= arive_radius)
		{
			object->TranslateDelta(-current_position.GetX(), -current_position.GetY(), -current_position.GetZ());
			axis_of_rotation = direction ^ (orientation);
			rotation_angle = acos((direction * (orientation) / (direction.Length() * orientation.Length())));
			if (rotation_angle > 0.25 || rotation_angle < -0.25)
			{
				if (axis_of_rotation.GetZ() >= 0)
					rotation_angle *= (-1);

				rotation_angle_safe = rotation_angle;
				if (rotation_angle >(max_rotation_speed * time))
					rotation_angle = (max_rotation_speed * time);
				if (rotation_angle < -(max_rotation_speed * time))
					rotation_angle = -(max_rotation_speed * time);
				object->RotateZDelta(rotation_angle);

				orientation = Vektoria::CHVector(
					orientation.GetX()*cos(rotation_angle) + orientation.GetY()*(-sin(rotation_angle)),
					orientation.GetX()*sin(rotation_angle) + orientation.GetY()*(cos(rotation_angle)),
					0);
			}
			object->TranslateDelta(current_position);

			if (rotation_angle_safe <= 0.75 && rotation_angle_safe >= -0.75)
			{
				direction = (orientation * max_movement_speed *time);
				object->TranslateDelta(direction.GetX(), direction.GetY(), ((target.GetZ() - current_position.GetZ()) * timedelta));
			}

		}
		else
		{
			time = 0;
			return false;
		}
		time = 0;
	}
	return true;
}
