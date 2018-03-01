#ifndef __RemoteResetTCPServer_H__
#define __RemoteResetTCPServer_H__

#include <Arduino.h>

#ifdef MDUINO_PLUS
#include <Ethernet2.h>
#else
#include <Ethernet.h>
#endif

#include <avr/wdt.h>

class RemoteResetTCPServer : public EthernetServer {
	public:
		explicit RemoteResetTCPServer(uint16_t port);

	public:
		void update();
};

#endif // __RemoteResetTCPServer_H__
