//the first time we go forward
void phase2() {
  int distance = getDistanceIn();
  if (distance < 16) {
    setMotors(155,155,0);
    x = 0;
  } else {
    x++;
  }
  
  if (x >= 3) {
    //the distance has been greater than or equal to 18 for 3 cycles now
    setMotors(0,0,0);
    delay(100);
    incrementPhase();
  }
}
