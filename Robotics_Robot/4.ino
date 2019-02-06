//passing the first obstacle
//the first time we go forward
void phase4() {
  int distance = getDistanceIn();
  if (distance == 0) {
    return;
  }
  if (distance < 35) {
    setMotors(175,175,90);
    x = 0;
  } else {
    x++;
  }
  
  if (x >= 1) {
    //the distance has been greater than or equal to 37 for 3 cycles now
    setMotors(0,0,0);
    delay(100);
    incrementPhase();
  }
}
