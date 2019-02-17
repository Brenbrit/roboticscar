//we're past the second set. turn to go around the third
void phase9() {
  if ((millis() - endTime) < 1700) {
    setMotors(timeSpeed,timeSpeed,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
  }
}
