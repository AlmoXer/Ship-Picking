#pragma once
#include <list>
#include "Animation.h"

/* Is responsible for doing every animation */
class CAnimationHandler
{
	CAnimationHandler();
	std::list<IAnimation*> animations;

public:	
	static CAnimationHandler &instance();

	/* All Animation files, they must implement the IAnimation Interface */
	CDroneCarrierAnimation droneCarrier;

	void Init();

	void addAnimation(IAnimation* a);
	void remove(IAnimation* a);
	void clear();

	/* Must be called every tick to play animations */
	void play(float fTimeDelta);
};

