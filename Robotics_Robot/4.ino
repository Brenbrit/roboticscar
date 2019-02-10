//passing the first obstacle
//the first time we go forward
void phase4() {
  int distance = getDistanceIn();
  disp(distance);
  if (distance >= 36) {
    setMotors(0,0,90);
    incrementPhase();
  } else {
    setMotors(100,100,90);
  }
}
