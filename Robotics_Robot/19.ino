void phase19() {
  if ((millis() - endTime) < 725) {
    setMotors(-timeSpeed,-timeSpeed,180);
  } else {
    setMotors(0,0,180);
    incrementPhase();
  }
}
