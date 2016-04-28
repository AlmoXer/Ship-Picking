#pragma once
#include <list>
#include "Vektoria\Root.h"
#include "../DroneCarrier.h"

using namespace Vektoria;

class IAnimation
{
public:
	virtual void play(float fTimeDelta) = 0;
};

class CDroneCarrierAnimation : public IAnimation
{
	std::list<CDroneCarrier*> carrier;
	float angularVelocityRingBridge;
	float angularVelocityRingMiddle;
	float angularVelocityRingDrive;
public:
	CDroneCarrierAnimation();

	void Init(float degpersec);
	void Init(float b, float m, float d);

	void setAngularVelocityDegRingBridge(float degpersec);
	void setAngularVelocityDegRingMiddle(float degpersec);
	void setAngularVelocityDegRingDrive(float degpersec);

	void addCarrier(CDroneCarrier* dc);
	void remove(CDroneCarrier* dc);
	void clear();

	void play(float fTimeDelta);
};
