#include "Address.h"
#include <WS2tcpip.h>
#include <cstdio>
#pragma comment( lib, "Ws2_32.lib" )
#undef SetPort
using namespace Net;

CAddress::CAddress(const char * addr, unsigned short port)
{
	SetAddress(addr);
	SetPOrt(port);
}


Net::CAddress::CAddress(unsigned long addr, port port)
{
	SetAddress(addr);
	SetPOrt(port);
}

CAddress::~CAddress()
{
}

void CAddress::SetAddress(const char * addr)
{
	int error = inet_pton(AF_INET,addr,&_address);
	if (error != 1) {
		if (error == 0) {
			printf("Argument is not a valid IPv4 Address!\n");
		}
		else if(error == -1){
			if (WSAGetLastError() == WSAEAFNOSUPPORT) {
				printf("Invalid Address Family Specified!\n");
			}
			else if (WSAGetLastError() == WSAEFAULT) {
				printf("Invalid Buffer(-length) Specified!\n");
			}
		}
	}
}

void CAddress::SetAddress(unsigned long addr)
{
	_address = htonl(addr);
}



void CAddress::SetPOrt(port port)
{
	_port = htons(port);
}

unsigned long CAddress::GetAddress() const
{
	return _address;
}

port CAddress::GetPort() const
{
	return _port;
}
