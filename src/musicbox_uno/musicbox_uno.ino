#include <Shieldbot.h>

#define UNO32_DEVICE 4
#define SENSOR_1 1
#define SENSOR_2 2
#define SENSOR_3 3
#define SENSOR_4 4
#define SENSOR_5 5

#define MOTOR_FORWARD 127

#define OUTPUT_PIN 11

Shieldbot sbot = Shieldbot();

void setup() {
  Serial.begin(9600); // serial for debugging (or sending to Processing)
  //Wire.begin(); // join i2c bus
  
  
}

void loop() {
  // read RPR-220 sensor and broadcast values
  sendSensorPayload();
  
  sbot.setMaxSpeed(50);
  sbot.drive(MOTOR_FORWARD, MOTOR_FORWARD);
  
  // pause (may have to change this when doing motor stuff
  delay(500);
}

void sendSensorPayload() {
  
  // simple bitmask to send that will indicate state of sensors
  //byte payload = B00000000;
  
  // read sensor 1
  if (sbot.readS1()) {
    tone(OUTPUT_PIN, 440, 100);
  }
  
  //read sensor 2
  /*
  if (sbot.readS2()) {
    payload |= (1 << SENSOR_2);
  }
  */
  
  // read sensor 3
  if (sbot.readS3()) {
    //payload |= (1 << SENSOR_3);
    tone(OUTPUT_PIN, 220, 100); 
  }
  
  // read sensor 4
  /*
  if (sbot.readS4()) {
    payload |= (1 << SENSOR_4);
  }
  */
  
  // read sensor 5
  if (sbot.readS5()) {
    //payload |= (1 << SENSOR_5);
    tone(OUTPUT_PIN, 110, 100);
  }
  
  //Serial.println(payload); // debugging info and/or processing
  
  // send payload to UNO32, which we marked as device #4
  //Wire.beginTransmission(UNO32_DEVICE);
  //Wire.write(payload);
  //Wire.endTransmission();
}
