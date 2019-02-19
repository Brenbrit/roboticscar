void phase17() {
  if ((millis() - endTime) < p17_19-75) {
    setMotors(timeSpeed,timeSpeed,180);
  } else {
    setMotors(0,0,180);
    incrementPhase();
  }
}
