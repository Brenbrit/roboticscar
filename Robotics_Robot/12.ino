void phase12() {
  if ((millis() - endTime) < 650) {
    setMotors(timeSpeed,timeSpeed,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
