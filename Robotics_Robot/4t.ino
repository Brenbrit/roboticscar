void phase4t() {
  if ((millis() - endTime) < 2750) {
    setMotors(timeSpeed,timeSpeed,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
    incrementPhase();
  }
}
