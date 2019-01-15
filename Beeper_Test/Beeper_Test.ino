
int startTime = millis();
short i = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
}

void loop() {
 if (i < 10) {
  if ((startTime + 250) > millis()) {
    digitalWrite(3, HIGH);
    delay(3);
    digitalWrite(3, LOW);
    delay(3);
    } else {
      delay (250);
      startTime = millis();
      i++;
   }
 }
}
