//passing the first obstacle
//the first time we go forward
void phase4() {
  int distance = getDistanceIn();
  disp(distance);
  //this one's hard
  //let's assume the robot can only see 22 inches
  if (distance < 20) {
    //keep on driving.
    setMotors(125,125,90);
  } else {
    //distance has reached 22. this is important
    timePerIn = ((millis() - firstDistanceTime) / (20-firstDistance));
    disp(0);
    incrementPhase();
    //timePerIn is the amount of time it takes us to drive one inch.
    //we'll use it to calculate how long to drive in step 5.
  }
}
