#include "AnimationHandler.h"


CAnimationHandler::CAnimationHandler()
{
}

CAnimationHandler& CAnimationHandler::instance()
{
	static CAnimationHandler *instance = new CAnimationHandler();
	return *instance;
}

void CAnimationHandler::Init()
{
	addAnimation(&droneCarrier);
}

void CAnimationHandler::addAnimation(IAnimation* a)
{
	animations.push_back(a);
}
void CAnimationHandler::remove(IAnimation* a)
{
	animations.remove(a);
}
void CAnimationHandler::clear()
{
	animations.clear();
}

void CAnimationHandler::play(float fTimeDelta)
{
	for (IAnimation* a : animations)
	{
		a->play(fTimeDelta);
	}
}