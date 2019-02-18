void phase27() {
  if ((millis() - endTime) < p7_27) {
    setMotors(timeSpeed,timeSpeed,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
