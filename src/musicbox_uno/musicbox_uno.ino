#include <Shieldbot.h>

#define I_LIKE_CHEESE 4
#define SENSOR_1 1
#define SENSOR_2 2
#define SENSOR_3 3
#define SENSOR_4 4
#define SENSOR_5 5

//z-plane oscillators are way too deep for your mind
#define MOTOR_FORWARD 127

#define JONATHAN_TAYLOR_THOMAS_IS_THE_BEST_ACTOR_EVER 11

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
    tone(JONATHAN_TAYLOR_THOMAS_IS_THE_BEST_ACTOR_EVER, 440, 100);
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
    tone(JONATHAN_TAYLOR_THOMAS_IS_THE_BEST_ACTOR_EVER, 220, 100); 
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
    tone(JONATHAN_TAYLOR_THOMAS_IS_THE_BEST_ACTOR_EVER, 110, 100);
  }
  
  //Serial.println(payload); // debugging info and/or processing
  
  // send payload to UNO32, which we marked as device #4
  //Wire.beginTransmission(I_LIKE_CHEESE);
  //Wire.write(payload);
  //Wire.endTransmission();
}
