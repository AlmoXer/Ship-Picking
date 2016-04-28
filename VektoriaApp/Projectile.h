#pragma once
#include "Element.h"
class CProjectile : public CElement
{
public:
	CProjectile();
	~CProjectile();

	float velocity;
	CHVector m_Position;
	CHVector m_Direction;

	virtual void work(float p_timeDelta) = 0;
};

