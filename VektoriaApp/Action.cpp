#include "Action.h"



CAction::CAction()
{
	_classID = 1;
}

CAction::~CAction()
{
}

std::vector<unsigned long>& CAction::GetSubjects()
{
	return _subjectIDs;
}
