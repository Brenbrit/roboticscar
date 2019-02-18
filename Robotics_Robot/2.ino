//the first time we go forward. should be 18in
void phase2() {
  if ((millis() - endTime) < p2_31) {
    setMotors(timeSpeed,timeSpeed,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
