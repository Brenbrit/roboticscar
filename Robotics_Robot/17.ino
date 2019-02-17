void phase17() {
  if ((millis() - endTime) < 800) {
    setMotors(timeSpeed,timeSpeed,180);
  } else {
    setMotors(0,0,180);
    incrementPhase();
  }
}
