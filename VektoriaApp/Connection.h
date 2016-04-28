#pragma once
#include "Socket.h"
#include "Packet.h"
#include "cereal/cereal.hpp"
#include "cereal/archives/portable_binary.hpp"
#define PACKET_BUFFER_SIZE 10240

namespace Net {
	class CConnection
	{
	public:
		CConnection();
		~CConnection();

		// listen
		void StartListening();
		void StartListening(port p);
		void ProcessRecieved();

		// send
		void Send(CPacket& p);


		// setters and getters
		void SetListenPort(port p);
		void SetClientAddress(CAddress clientAddress);
		float GetPing();

	private:
		void SendAck(long packageID);
		void SendClose();
		void SendPing();

	private:
		CSocket _socket;
		port _listenPort;
		CAddress _clientAddress;

		float _packageInterval = 0.1;
		float _timeout = 1;
		float _timeSinceLastRecievedPackage = 0;
		float _ping;

		char _recvBuffer[PACKET_BUFFER_SIZE];
	};



}


bool inline InitSockets() {
	WSADATA WsaData;
	return WSAStartup(MAKEWORD(2, 2), &WsaData) == NO_ERROR;
}

void inline ShutdownSockets() {
	WSACleanup();
}