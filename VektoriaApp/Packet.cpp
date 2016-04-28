#include "Packet.h"



Net::CPacket::CPacket()
{
	_foreign_id = 0;
	_data = std::string();
}

//creates a copy of the string data
Net::CPacket::CPacket(classID foreignID, std::string& data)
{
	_foreign_id = foreignID;
	_data = std::string(data);
}

Net::CPacket::~CPacket()
{
}


classID Net::CPacket::GetForeignClassID() const
{
	return _foreign_id;
}

const std::string& Net::CPacket::GetData() const
{
	return _data;
}

void Net::CPacket::Set(classID foreignID, const std::string& data)
{
	_foreign_id = foreignID;
	_data = std::string(data);
}
