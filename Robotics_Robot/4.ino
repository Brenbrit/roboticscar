//passing the first obstacle
//the first time we go forward
void phase4() {
  int distance = getDistanceIn();
  if (distance < 37) {
    setMotors(155,155,90);
    x = 0;
  } else {
    x++;
  }
  
  if (x >= 3) {
    //the distance has been greater than or equal to 37 for 3 cycles now
    setMotors(0,0,0);
    delay(100);
    incrementPhase();
  }
}
