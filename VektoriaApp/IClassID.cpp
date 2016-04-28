#include "IClassID.h"



IClassID::IClassID(classID id)
{
	_classID = id;
}

IClassID::~IClassID()
{
}

classID IClassID::GetClassID()
{
	return _classID;
}
