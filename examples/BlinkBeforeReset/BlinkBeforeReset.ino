// RemoteResetTCPServer library example
// by Industrial Shields

// Fast blink Q0.0 before reset

#ifdef MDUINO_PLUS
#include <Ethernet2.h>
#else
#include <Ethernet.h>
#endif

#include <RemoteResetTCPServer.h>

// Define the network parameters
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10, 10, 10, 25);

// Create the autoreset server using the TCP port 2000
RemoteResetTCPServer resetServer(2000);

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // Start the Ethernet
  Ethernet.begin(mac, ip);

  // Start the remote reset server
  resetServer.begin();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // Update the remote reset server periodically
  resetServer.update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void remoteResetTCPEvent() {
  // Fast blink Q0.0 before reset
  for (int i = 0; i < 20; ++i) {
    digitalWrite(Q0_0, HIGH);
    delay(50);
    digitalWrite(Q0_0, LOW);
    delay(50);
  }
}
