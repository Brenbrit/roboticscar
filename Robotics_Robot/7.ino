//drive towards the right wall.
void phase7() {
  if (getDistanceIn() > 6) {
    setMotors(-100,-100,0);
  } else {
    setMotors(0,0,0);
    incrementPhase();
  }
}
