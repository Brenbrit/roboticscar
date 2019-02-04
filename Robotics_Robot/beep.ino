//for using the cute little beeper plugged into pin 3
void beep(int duration, int count) {
  int i = 0;
  int startTime = millis();
  while (i < count) {
    if ((startTime + duration) > millis()) {
    digitalWrite(beeperPin, HIGH);
    delay(1);
    digitalWrite(beeperPin, LOW);
    delay(1);
    } else {
      if (i != (count-1)) {
        delay (duration);
      }
      startTime = millis();
      i++;
   }
  }
}
