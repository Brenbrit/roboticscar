//the first time we go forward. should be 18in
void phase2() {
  if ((millis() - endTime) < 1150) {
    setMotors(timeSpeed,timeSpeed,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
