// RemoteResetTCPServer library example
// by Industrial Shields

// Blink Q0.0, while waiting for a remote reset

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

// Blinking variables
uint32_t lastToggleTime = 0UL;
int pinValue = LOW;

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

  // Blink Q0.0 with a period of 1s
  if (millis() - lastToggleTime > 500) {
    pinValue = (pinValue == HIGH ? LOW : HIGH);
    digitalWrite(Q0_0, pinValue);
    lastToggleTime = millis();
  }
}
