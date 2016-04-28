#pragma once
#include "ApiRenderDistributed/NetworkBase.h"
#include "Address.h"

namespace Net {
	class CSocket {
	public:
		CSocket();
		~CSocket();
		void Open(port p);
		void Close();
		void Send(const CAddress& destination, const void* data, unsigned int size);
		int Recieve(CAddress & out_reciever, void* out_buffer, unsigned int size);

	private:
		int _socketHandle;
	};
}