//drive towards the right wall.
void phase7() {
  if ((millis() - endTime) < p7_27) {
    setMotors(timeSpeed,timeSpeed,180);
  } else {
    setMotors(0,0,180);
    incrementPhase();
  }
} //haha easter egg found
