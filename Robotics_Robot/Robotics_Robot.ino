#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <SparkFun_TB6612.h>
#include "SevSeg.h"


SevSeg sevseg; 



//set up some variables first

//the offsets for the motors. either 1 or -1
const int offsetA = 1;
const int offsetB = -1;

const int trigPin = 4;
const int echoPin = 12;

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


//the next vars are used in the distance detection
const int maxDistance = 100;
const int minDistance = 2;

//this is used for the sensor - only output once every bnoi times. set to -1 for no printing.
int bnoCounter = 0;
int bnoi = 50;

//this is used for the distance outputting - only output every distancei times. set to -1 for no printing.
int distanceCounter = 0;
int distancei = 0;
long lastGoodDistance;
int lastGoodTime;

//we don't want the robot to start as soon as you plug it in
int killPin;

//for the beeper
int beeperPin = 3;

//the globals for driving speed
int driverSpeed = 0;
int passSpeed = 0;

//the step that we are on.
int phase = 0;

int endTime = 0;

int x = 0;

//for recursion problems
int startRec;
bool recursing = false;

//for the bad phases
int firstDistance;
int firstDistanceTime;
int timePerIn;
