#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <SparkFun_TB6612.h>



//set up some variables first

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

//for the blue sensor chip
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//for measuring the distance. I'll just stick to 2 pins right now because I don't need anymore at the moment
//lol was he dumb. I don't need anymore right now either tho. Bet I'll eat my words in a few hours
//ok future Brendan here. we def need that pin, so I named it ultrapin for the ultrasonic sensor and because it serves two functions.
const int ultraPin = 12;

//the next vars are used in the distance detection
const float maxDistance = 98.4f;
const float minDistance = 5.5f;

//this is used for the sensor - only output once every bnoi times. set to -1 for no printing.
int bnoCounter = 0;
int bnoi = 50;

//this is used for the distance outputting - only output every distancei times. set to -1 for no printing.
int distanceCounter = 0;
int distancei = 50;

//we don't want the robot to start as soon as you plug it in
int killPin = 4;

//for the beeper
int beeperPin = 3;

//the globals for driving speed
int driverSpeed = 0;
int passSpeed = 0;

//for the math we do to figure out how to turn.
long idealDirection = 0;

//the step that we are on.
int phase = 0;

int endTime = 0;


//this function converts two variables into real motor movement. both speeds are from 0-255
void setMotors(int driverSpeed, int passSpeed, boolean errorCorrection) {

  if (errorCorrection) {
    //finally, set the motors to their correct speeds.
    sensors_event_t event;
    bno.getEvent(&event);
    if (event.orientation.x < 180) {
      //we're turned perfectly or to the right
     driverSpeed = round(255 - ( 10 * event.orientation.x));
      passSpeed = 255;
    } else {
      //we're turned at least a little to the left
      driverSpeed = 255;
      passSpeed = round(255 + ( 10 * (event.orientation.x - 360 )));
   }
  }
  
  motor1.drive(driverSpeed);
  motor2.drive(passSpeed);
}




//for using the ultrasonic distance sensor
//assumes the ultraPin is set to some integer that can be understood
float getDistanceIn() {

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
  phase = 1;
}



//for using the cute little beeper plugged into pin 3
void beep(int duration, int count) {
  int i = 0;
  int startTime = millis();
  while (i < count) {
    if ((startTime + duration) > millis()) {
    digitalWrite(beeperPin, HIGH);
    delay(3);
    digitalWrite(beeperPin, LOW);
    delay(3);
    } else {
      if (i != (count-1)) {
        delay (duration);
      }
      startTime = millis();
      i++;
   }
  }
}



void incrementPhase() {
  phase++;
  endTime = millis();
}


void phase1() {
  beep(250,4);
  incrementPhase();
}


void phase2() {
  setMotors(255,255,true);
  Serial.println(int(getDistanceIn));
  if (getDistanceIn() >= 17.5f) {
    incrementPhase();
  }
}

void phase3() {
  motor1.brake();
  motor2.brake();
  delay(10000);
}

void phase4() {
  if ((millis() - endTime) >= 1000) {
    setMotors(-255,255,false);
  } else{
    setMotors(255,-255, false);
  }
  if ((millis() - endTime) >= 2000) {
    //incrementPhase();
    motor1.brake();
    motor2.brake();
  }
}

void phase5() {
  setMotors(0,0,true);
  if ((millis() - endTime) >= 1000) {
    incrementPhase();
  }
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



void doPhase(int phase) {
  if (phase == 1) {
    phase1();
  }
  if (phase == 2) {
    phase2();
  }
  if (phase == 3) {
    phase3();
  }
  if (phase == 4) {
    phase4();
  }
  if (phase == 5) {
    phase5();
  }
}



void loop() {
  
  //set the default driving speed to 0.
  int driverSpeed = 0;
  int passSpeed = 0;

  doPhase(phase);

  Serial.println(phase);

  if (digitalRead(killPin) == HIGH) {
    
    driverSpeed = 0;
    passSpeed = 0;

    setMotors(0,0,false);
    delay(5);
  } //end first killPin read


}
