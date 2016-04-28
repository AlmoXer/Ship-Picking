#include "Socket.h"
#include <stdexcept>
using namespace Net;

CSocket::CSocket()
{
}

CSocket::~CSocket()
{
	Close();
}

void CSocket::Open(port p)
{
	_socketHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (_socketHandle <= 0) {
		throw std::exception("Failed to create Socket", _socketHandle);
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET; //recieve IPv4 addresses only
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(p);

	if (bind(_socketHandle, (const sockaddr*)&addr, sizeof(sockaddr_in)) == SOCKET_ERROR) {
		throw std::exception("Failed to bind socket to given port; bind(...)", WSAGetLastError());
	}


	DWORD nonBlocking = 1;
	//set 'IO control socket' to 'force IO to NonBlocking-IO'
	if (ioctlsocket(_socketHandle, FIONBIO, &nonBlocking)) {
		throw std::exception("Failed to set socket to non blocking; ioctlsocket(...)", WSAGetLastError());
	}
}

void CSocket::Close()
{
	closesocket(_socketHandle);
}

void CSocket::Send(const CAddress& destination, const void* data, unsigned int size)
{
	sockaddr_in destAddress;
	destAddress.sin_family = AF_INET;
	destAddress.sin_addr.s_addr = destination.GetAddress();
	destAddress.sin_port = destination.GetPort();

	int sentBytes = sendto(_socketHandle, (const char*)data, size, 0, (sockaddr*)&destAddress, sizeof(sockaddr_in));

	if (sentBytes != size) {
		throw std::exception("Failed to send packet; sendto(...)");
	}
	
}

int CSocket::Recieve(CAddress & out_senderAddress, void* out_buffer, unsigned int const bufferSize)
{
	sockaddr_in from;
	int fromSize = sizeof(sockaddr_in);
	int recievedBytes = recvfrom(_socketHandle, (char*)out_buffer, bufferSize, 0, (sockaddr*)&from, &fromSize);
	
	out_senderAddress.SetAddress(from.sin_addr.s_addr);
	out_senderAddress.SetPOrt(ntohs(from.sin_port));
	return recievedBytes;
}
