#include <Keyboard.h>
#include <SoftwareSerial.h> 
SoftwareSerial mySerial(8, 9); // RX, TX


void setup() {  
  Keyboard.begin();
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    uint8_t rxchar = mySerial.read();
    Keyboard.press(rxchar);
    delay(20);
    Keyboard.release(rxchar);
    mySerial.write(rxchar);
  }
}
