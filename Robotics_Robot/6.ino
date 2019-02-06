//passed the first set of obstacles, getting out of the way of the second set
void phase6() {
  int distance = getDistanceIn();
  if (distance == 0) {
    return;
  }
  if (distance < 31) {
    setMotors(155,155,180);
    x = 0;
  } else {
    x++;
  }
  
  if (x >= 2) {
    //the distance has been greater than or equal to 37 for 3 cycles now
    setMotors(0,0,0);
    delay(100);
    incrementPhase();
  }
}
