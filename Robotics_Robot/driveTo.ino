//ok, here's the function that will be hard to write.
//we want to have a few args. First, the desired distance and the angle.
//next, we want to know how close to slow down and to what degree. Minimum movement speed is always 80.

bool driveTo(int goalDistance, int angle, int slowDistance, int slowMulti) {
  //obvoisly, we need to know how far we are from the nearest thing. we'll start over if we catch a 0 slackin
  int distance = getDistanceIn();
  if (distance == 0) {
    return false;
  }

  //ok, now we have a usable distance.
  //let's see if we overshot the goal first.
  if (distance > goalDistance) {
    //aah! I don't know if the bot goes straight back yet!
    setMotors(-100,-100,angle);
  }

  //we know now that the bot hasn't overshot yet. 
  
}
