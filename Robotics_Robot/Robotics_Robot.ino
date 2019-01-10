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
long duration;
int distance;
const int maxDistance = 250;
const int minDistance = 14;

//temporary. If true, the machine will stop moving completely until reset.
bool permaStop = false;

//if this ever gets to be 3, the bot will stop.
int stopCounter = 0;

//this is used for the sensor - only output once every 10 times
int bnoCounter = 0;

//we don't want the robot to start as soon as you plug it in
int startPin = 4;
bool delayStart = true;


void setup() {
  Serial.begin(9600);
  digitalWrite(13, LOW);
  pinMode(startPin, INPUT);

  
  //try to begin the bno sensor
  Serial.println("beginning the bno");
  bno.begin();
  Serial.println("bno began. setting crystal now");
  bno.setExtCrystalUse(true);
  Serial.println("bno beginning completed.");

  Serial.println("Finished setup");
}



void loop() {

  if (permaStop) {
    motor1.brake();
    motor2.brake();
  } else {
    if (!delayStart) {
      //the start pin has been released. we're free!
      motor1.drive(255);
      motor2.drive(255);
    } else {
      //the start pin is still in. Let's check
      if (digitalRead(startPin) == HIGH) {
        //yep, it's still in there.
        Serial.println("Waiting for pin 4");
      } else {
        delayStart = false;
      }
    }
  }

  //for the sensor
  //bno.setExtCrystalUse(true);
  
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
  
  //to figure out the distance, we use (0.0343/2) for the speed of sound and half the time it took our sound to be sent out and return
  distance = duration*0.01715;
  
  // Prints the distance if it's less than or equal to the maximum distance defined by maxDistance
  if (distance <= maxDistance && distance >= minDistance) {
    
    //output the distance to the serial port. Maybe comment out for application
    Serial.print(distance);
    Serial.println("cm");

    //for the stop part
    if (distance <= 20) {
      stopCounter++;
      if (stopCounter >= 3) {
        permaStop = true;
        Serial.println("stopped");
      }
    }
    
  }

  sensors_event_t event;
  bno.getEvent(&event);
  
  if (bnoCounter == 0) {
    //output the sensor data for the car's orientation every 10th time
    Serial.print("X");
    Serial.print(event.orientation.x, 4);
    Serial.print("\tY");
    Serial.print(event.orientation.y, 4);
    Serial.print("\tZ");
    Serial.println(event.orientation.z, 4);
    bnoCounter++;
  } else {
    if (bnoCounter == 10) {
      bnoCounter = 0;
    } else {
      bnoCounter++;
    }
  }

  if (event.orientation.z >= 20) {
    permaStop = true;
  } 
  if (event.orientation.z <= -20) {
    permaStop = true;
  }
  if (event.orientation.y >= 20) {
    permaStop = true;
  }
  if (event.orientation.y <= -20) {
    permaStop = true;
  }

  //if we don't delay this loop, the sensor will constantly output 7 or 8 cm. do not do not remove.
  //what is life without some spice?
  //delay(10);

}
