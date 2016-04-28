#pragma once
typedef unsigned char uchar;
typedef unsigned short port;

namespace Net {
	class CAddress {
	public:
		CAddress(const char* addr = "127.0.0.1", port port = 0);
		CAddress(unsigned long addr, port port = 0);
		~CAddress();

		void SetAddress(const char* addr);
		void SetAddress(unsigned long addr);
		void SetPOrt(port port);

		unsigned long GetAddress() const;
		port GetPort() const;

	private:
		unsigned long _address;
		port _port;
	};
}