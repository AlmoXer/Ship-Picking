#include "Animation.h"

CDroneCarrierAnimation::CDroneCarrierAnimation()
{
	angularVelocityRingBridge = 0.25f;
	angularVelocityRingMiddle = -0.3f;
	angularVelocityRingDrive = 0.4f;
}
void CDroneCarrierAnimation::Init(float degpersec)
{
	setAngularVelocityDegRingBridge(degpersec);
	setAngularVelocityDegRingMiddle(degpersec);
	setAngularVelocityDegRingDrive(degpersec);
}
void CDroneCarrierAnimation::Init(float b, float m, float d)
{
	setAngularVelocityDegRingBridge(b);
	setAngularVelocityDegRingMiddle(m);
	setAngularVelocityDegRingDrive(d);
}

void CDroneCarrierAnimation::setAngularVelocityDegRingBridge(float degpersec)
{
	angularVelocityRingBridge = (degpersec * 360) / (2 * PI);
}
void CDroneCarrierAnimation::setAngularVelocityDegRingMiddle(float degpersec)
{
	angularVelocityRingMiddle = (degpersec * 360) / (2 * PI);
}
void CDroneCarrierAnimation::setAngularVelocityDegRingDrive(float degpersec)
{
	angularVelocityRingDrive = (degpersec * 360) / (2 * PI);
}

void CDroneCarrierAnimation::addCarrier(CDroneCarrier* dc)
{
	carrier.push_back(dc);
}
void CDroneCarrierAnimation::remove(CDroneCarrier* dc)
{
	carrier.remove(dc);
}
void CDroneCarrierAnimation::clear()
{
	carrier.clear();
}
void CDroneCarrierAnimation::play(float fTimeDelta)
{
	for (CDroneCarrier* dc : carrier)
	{
		dc->m_Orbit[0].RotateZDelta(angularVelocityRingBridge * fTimeDelta);
		dc->m_Orbit[1].RotateZDelta(angularVelocityRingMiddle * fTimeDelta);
		dc->m_Orbit[2].RotateZDelta(angularVelocityRingDrive * fTimeDelta);
	}
}
