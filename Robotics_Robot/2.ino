//the first time we go forward. should be 18in
void phase2() {
  int distance = getDistanceIn();
  disp(distance);
  if (distance >= 16) {
    setMotors(0,0,0);
    incrementPhase();
  } else {
    setMotors(100,100,0);
  }
}
