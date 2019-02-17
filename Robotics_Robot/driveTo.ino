//ok, here's the function that will be hard to write.
//we want to have a few args. First, the desired distance and the angle.
//next, we want the base speed and the absolute minimum speed to go to. This should probably be above 80 imo
//finally, we need to know the distance to start slowing down. this is linear

bool driveTo(int goalDistance, int angle, int baseSpeed, int terminalSpeed, int slowDistance) {
  int distance = getDistanceIn();
  
  if (distance == goalDistance) {
    setMotors(0,0,angle);
    delay(250);
    if (getDistanceIn() == goalDistance) {
      setMotors(0,0,angle);
      return true;
    }
  }

  

  //ok, now we have a usable distance.
  //let's see if we overshot the goal first.
  if (distance > goalDistance) {
    //aah! I don't know if the bot goes straight back yet!
    setMotors(-100,-100,angle);
    return false;
  }

  if (distance < (goalDistance - slowDistance)) {
    //we haven't reached the point at which we slow down yet
    setMotors(baseSpeed,baseSpeed,angle);
    return false;
  }

  //OOH! here's where things get good
  long m = -((goalDistance-slowDistance)/(baseSpeed-terminalSpeed));
  int futureSpeed = m*(distance-slowDistance)+baseSpeed;

  if (futureSpeed < terminalSpeed) {
    futureSpeed = terminalSpeed;
  }

  //we're still on the line, baby!
  setMotors(futureSpeed,futureSpeed,angle);
  return false;

  
  
}
