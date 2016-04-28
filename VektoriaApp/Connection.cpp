#include "Connection.h"
#include <iostream>
#include "cereal/cereal.hpp"
#include "cereal/archives/portable_binary.hpp"
#include "IClassID.h"
#include "TestClass.h"
#include "MoveAction.h"
using namespace Net;


CConnection::CConnection()
{
	_socket = CSocket();
	
}


CConnection::~CConnection()
{
}

void Net::CConnection::StartListening()
{
	_socket.Open(_listenPort);
}

void CConnection::StartListening(port p)
{
	SetListenPort(p);
	StartListening();
}

void CConnection::ProcessRecieved()
{
	CAddress remote_address;
	while (true)
	{
		int bytes_recieved = _socket.Recieve(remote_address, _recvBuffer, PACKET_BUFFER_SIZE);
		if(bytes_recieved<=0)
		{
			break;
		}
		
		CPacket packet;

		
		std::stringstream stream = std::stringstream(std::string(_recvBuffer, bytes_recieved));
		cereal::PortableBinaryInputArchive pbia = cereal::PortableBinaryInputArchive(stream);
		pbia(packet);// deserialize packet
		

		std::stringstream datastream = std::stringstream(packet.GetData());
		cereal::PortableBinaryInputArchive pbia_data_archive = cereal::PortableBinaryInputArchive(datastream);

		
		


		switch(packet.GetForeignClassID())
		{
		case ACTION_MOVE:
		{
			CMoveAction* mac_action = new CMoveAction();
			pbia_data_archive(*mac_action);
			mac_action->Execute();
			break;
		}
		default:
			std::cout << "ClassID: " << packet.GetForeignClassID() << std::endl;
			std::cout << "Data:\n" << packet.GetData() << std::endl;
			break;
		}
		
	}
}

// serializes packet and sends it through the socket
void CConnection::Send(Net::CPacket& p)
{
	std::stringstream str;
	cereal::PortableBinaryOutputArchive bia_archive = cereal::PortableBinaryOutputArchive(str);
	bia_archive(p);
	std::string string = str.str();
	const char* cstr = string.c_str();
	_socket.Send(_clientAddress, cstr, string.length());

}

void CConnection::SetListenPort(port p)
{
	_listenPort = p;
}

void CConnection::SetClientAddress(CAddress clientAddress)
{
	_clientAddress = clientAddress;
}

float CConnection::GetPing()
{
	return _ping;
}

void CConnection::SendAck(long packageID)
{
}

void CConnection::SendClose()
{
}

void CConnection::SendPing()
{
}
