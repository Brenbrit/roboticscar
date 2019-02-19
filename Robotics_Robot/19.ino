void phase19() {
  if ((millis() - endTime) < p17_19-225) {
    setMotors(timeSpeed,timeSpeed,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
