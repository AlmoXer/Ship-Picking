#include "MoveAction.h"


CMoveAction::CMoveAction()
{
	_classID = ACTION_MOVE;
}

CMoveAction::CMoveAction(Net::CPacket* initializer) : CMoveAction()
{
	if(initializer->GetForeignClassID() != _classID)
	{
		throw std::invalid_argument("Packet does not contain data corresponding to this class!");
	}

	std::stringstream strstream = std::stringstream(initializer->GetData());
	cereal::PortableBinaryOutputArchive bia_archive(strstream);// constructor
	bia_archive((*this));
}

CMoveAction::~CMoveAction()
{
}


Net::CPacket* CMoveAction::BuildPacket()
{
	Net::CPacket* packet = new Net::CPacket();
	std::stringstream stream;
	cereal::PortableBinaryOutputArchive bia = cereal::PortableBinaryOutputArchive(stream);
	bia(*this);
	packet->Set(_classID, stream.str());
	return packet;
}

void CMoveAction::Add(shipID subjID, float dest_x, float dest_y)
{
	_subjectIDs.push_back(subjID);
	_destinations.push_back(dest_x);
	_destinations.push_back(dest_y);
}

void CMoveAction::Execute()
{
	// execute movement action here
	
}

