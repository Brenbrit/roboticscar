#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <SparkFun_TB6612.h>

//the offsets for the motors. either 1 or -1
const int offsetA = 1;
const int offsetB = 1;

//pins for all motor inputs. That's a lot, right?!?!?!?!
//please ignore the fact that they're all out of order.
#define PWMA 11
#define AIN2 10
#define AIN1 9
#define STBY 8
#define BIN1 7
#define BIN2 6
#define PWMB 5

//the driver side motor
Motor motor2 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
//the passenger side motor
Motor motor1 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int startTime = millis();
short i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  motor1.drive(255);
  motor2.drive(255);
  delay(1000);
  motor1.drive(0);
  motor2.drive(0);
  delay(500);
  
  motor1.drive(255);
  motor2.drive(-255);
  delay(1500);
  motor1.drive(-255);
  motor2.drive(255);
  delay(1500);
  motor1.drive(0);
  motor2.drive(0);
  delay(500);
  motor1.drive(-255);
  motor2.drive(-255);
  delay(1000);
  motor1.drive(0);
  motor2.drive(0);
}

void loop() {
 if (i < 4) {
  if ((startTime + 250) > millis()) {
    digitalWrite(3, HIGH);
    delay(1);
    digitalWrite(3, LOW);
    delay(1);
    } else {
      delay (250);
      startTime = millis();
      i++;
   }
 }
}
