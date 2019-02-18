void phase31() {
  if ((millis() - endTime) < p2_31) {
    setMotors(timeSpeed,timeSpeed,180);
  } else {
    setMotors(0,0,180);
    incrementPhase();
  }
}
