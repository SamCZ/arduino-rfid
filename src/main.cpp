#include <Arduino.h>
#include <SoftwareSerial.h>

#define rxPin D2
#define txPin D3

SoftwareSerial rfid( rxPin, 0 );

void setup() {
  Serial.begin(9600);   // Serial port for connection to host
  rfid.begin(9600);      // Serial port for connection to RFID module

  Serial.println("RFID Reader Initialized");
}

int findTag( char tagValue[10] );
void unlock();


/**
 * Loop
 */
void loop() {
  byte i         = 0;
  byte val       = 0;

  if((val = rfid.read()) == 2) {
    for(i = 0; i < 12; i++) {
      while(rfid.available() == 0);
      int val = rfid.read();

      Serial.print((char)val);
      Serial.print(" ");
    }
    Serial.println();
  }
}