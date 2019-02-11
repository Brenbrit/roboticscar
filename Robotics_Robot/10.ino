//we are driving past the second set of obstacles now
void phase10() {
  //endTime is the time that this phase started
  if (millis() < (endTime + (timePerIn * 11))) {
    setMotors(100,100,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
  }
}
