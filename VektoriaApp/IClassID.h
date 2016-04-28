#pragma once
typedef unsigned int classID;
class IClassID
{
public:
	IClassID(classID id = 0);
	virtual ~IClassID();
	classID GetClassID();
protected:
	classID _classID;
};


enum CLASSID { DEFAULT, ACTION = 1, TEST = 7357, ACTION_MOVE = 2 };

