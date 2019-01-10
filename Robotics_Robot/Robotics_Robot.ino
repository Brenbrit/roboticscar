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


int startPin = 4;



void setup() {
  Serial.begin(9600);
  pinMode(startPin, INPUT);
  
  while (digitalRead(startPin) == HIGH) {
    //do nothing bc start pin is still high.
    delay(500);
  }
  delay(1000);

  Serial.println("Finished setup");

  motor1.drive(255);
  motor2.drive(255);
}

void loop() {

  if (permaStop) {
    motor1.brake();
    motor2.brake();
    delay(1000);
    return;
  }
  
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
    Serial.println(distance);

    //for the stop part
    if (distance <= 20) {
      stopCounter++;
      if (stopCounter >= 3) {
        permaStop = true;
        Serial.println("stopped");
      }
    }
    
  }

  //if we don't delay this loop, the sensor will constantly output 7 or 8 cm. do not do not remove.
  //what is life without some spice?
  //delay(10);

}
