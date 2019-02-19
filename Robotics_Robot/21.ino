void phase21() {
  if ((millis() - endTime) < p14_21-100) {
    setMotors(timeSpeed,timeSpeed,270);
  } else {
    setMotors(0,0,270);
    incrementPhase();
  }
}
