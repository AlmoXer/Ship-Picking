#pragma once
#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

class CMovement
{
public:
	Vektoria::CHVector orientation;
	Vektoria::CHVector direction;
	Vektoria::CHVector axis_of_rotation;
	Vektoria::CHVector current_position;
	Vektoria::CPlacement *object;

	//Winkel aus der Matrix berechnen.
	float x, y, z;

	float rotation_angle;
	float max_rotation_speed;
	float max_movement_speed;
	float arive_radius;
	float distance;
	float time;
	float executions_per_second;

	float rotation_angle_safe;


	void init(Vektoria::CPlacement *p_movingobject);
	bool arrive(Vektoria::CHVector target, float timedelta);
	bool arriveDrone(Vektoria::CHVector target, float timedelta);
	CMovement();
	~CMovement();
};
