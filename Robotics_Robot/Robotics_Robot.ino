#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <SparkFun_TB6612.h>



//set up some variables first

//the offsets for the motors. either 1 or -1
const int offsetA = -1;
const int offsetB = -1;

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
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
//the passenger side motor
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

//for the blue sensor chip
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//for measuring the distance. I'll just stick to 2 pins right now because I don't need anymore at the moment
//lol was he dumb. I don't need anymore right now either tho. Bet I'll eat my words in a few hours
//ok future Brendan here. we def need that pin, so I named it ultrapin for the ultrasonic sensor and because it serves two functions.
const int ultraPin = 12;

//the next vars are used in the distance detection
const long maxDistance = 98.4;
const long minDistance = 5.5;

//this is used for the sensor - only output once every bnoi times. set to -1 for no printing.
int bnoCounter = 0;
int bnoi = 50;

//this is used for the distance outputting - only output every distancei times. set to -1 for no printing.
int distanceCounter = 0;
int distancei = 50;

//we don't want the robot to start as soon as you plug it in
int killPin = 4;

//the globals for driving speed
int driverSpeed = 0;
int passSpeed = 0;

//for the math we do to figure out how to turn.
long idealDirection = 0;


void setup() {
  Serial.begin(9600);
  pinMode(killPin, INPUT);

  
  //try to begin the bno sensor
  Serial.println("beginning the bno");
  bno.begin();
  Serial.println("bno began. setting crystal now");
  bno.setExtCrystalUse(true);
  Serial.println("bno beginning completed.");

  Serial.println("Finished setup");
}



void loop() {
  
  //set the default driving speed to 0.
  int driverSpeed = 0;
  int passSpeed = 0;


  //the last thing we will do in the loop function is set the wheels to move however fast they're supposed to go.
  setMotors(driverSpeed, passSpeed);
}




//for using the ultrasonic distance sensor
//assumes the ultraPin is set to some integer that can be understood
long getDistanceIn() {

  //variables we will use for the calculating
  long duration;
  long distance;
  
  //set ultra to trig mode, write LOW
  pinMode(ultraPin, OUTPUT);
  digitalWrite(ultraPin, LOW);
  delayMicroseconds(2);
  //ultra is still in trig mode, send the signal
  digitalWrite(ultraPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraPin, LOW);
  //set the ultraPin to sensor mode, read
  pinMode(ultraPin, INPUT);
  duration = pulseIn(ultraPin, HIGH);
  //to figure out the distance, we use (0.0133/2) for the speed of sound and half the time it took our sound to be sent out and return
  distance = duration*0.00665;

  //only use if the distance is reasonable
  if (distance >= minDistance && distance <= maxDistance) {
    return distance;

    if (distanceCounter == distancei) {
      //the time has come! We will print the distance to the console
      Serial.print(distance);
      Serial.println("in");
      distanceCounter == 0;
      
    } else {
      distanceCounter++;
    }
    
  } //end reasonable distance check
  
} //end get distance



//this function converts two variables into real motor movement. both speeds are from 0-255
void setMotors(int driverSpeed, int passSpeed) {
  //before we go setting the motors, let's check if the kill switch is put in.
  if (digitalRead(killPin) == HIGH) {
    
    //ok, we read it once. We will do it two more times to make absolutely sure this is what's supposed to happen.
    if (digitalRead(killPin) == HIGH) {
      if (digitalRead(killPin) == HIGH) {
        
        //the pin is probably in. Don't run the motors.
        driverSpeed = 0;
        passSpeed = 0;
        
      } //end third killPin read
    } //end second killPin read
  } //end first killPin read

  //finally, set the motors to their correct speeds.
  motor1.drive(driverSpeed);
  motor2.drive(passSpeed);
}



//this is for getting the absolute x coord
long getX() {
  sensors_event_t event;
  bno.getEvent(&event);
  long x = event.orientation.x;
  return x;
}

long getBetterX() {
  long betterX;
  sensors_event_t event;
  bno.getEvent(&event);
  long x = event.orientation.x;
  if (idealDirection > 180) {
    //x - ideal for every real measurement between ideal and ideal-180
    if (x <= idealDirection && x >= (idealDirection-180)) {
      return(x-idealDirection);
    }
    //
    if (x-idealDirection < 0) {
      return(
    }
  }
}

//returns the robot's y rotation
long getY() {
  sensors_event_t event;
  bno.getEvent(&event);
  long y = event.orientation.y;
  return y;
}

//returns the robot's z rotation
long getZ() {
  sensors_event_t event;
  bno.getEvent(&event);
  long z = event.orientation.z;
  return z;
}

