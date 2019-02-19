void phase25() {
  if ((millis() - endTime) < p9_25+2300) {
    setMotors(timeSpeed,timeSpeed,285);
  } else {
    setMotors(0,0,285);
    beep(200,4);
    //incrementPhase();
  }
}
