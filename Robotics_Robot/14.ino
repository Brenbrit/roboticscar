void phase14() {
  if ((millis() - endTime) < p14_21) {
    setMotors(timeSpeed,timeSpeed,90);
  } else {
    setMotors(0,0,90);
    incrementPhase();
    incrementPhase();
  }
}
