#pragma once
#include "Laser.h"

class CTurretMovement
{
public:

	CLaser *m_Laser;

	CHMat StartRotation;
	Vektoria::CHVector direction;
	Vektoria::CHVector Startdirection;
	Vektoria::CHVector axis_of_rotation;
	Vektoria::CHVector current_position;
	Vektoria::CHVector current_position_to_Ship;

	float rotation_angle;
	
	float time;
	float angleZ;
	float distance;

	float Ergebnis;

	void Init(CLaser *p_Laser, Vektoria::CHVector p_Orientation);
	bool moveToTarget(float p_TimeDelta, CPlacement *p_Target);
	bool moveToOrientation();
	bool moveToStartPosition();

	float absolutRotation;
	float relativeRotation;

	CTurretMovement();
	~CTurretMovement();
};

