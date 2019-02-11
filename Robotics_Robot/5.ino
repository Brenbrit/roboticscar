//we have the timePerIn from phase 4, use it to drive the last 14 inches.
void phase5() {
  //endTime is the time that this phase started
  if (millis() < (endTime + (timePerIn * 14))) {
    setMotors(125,125,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
  }
}
