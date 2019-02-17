void phase14() {
  if ((millis() - endTime) < 2175) {
    setMotors(timeSpeed,timeSpeed,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
    incrementPhase();
  }
}
