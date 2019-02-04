void turn(int degree) {
  bool turning = true;
  while (turning) {
    int variation = getVariation(degree);
    int motorSpeed = abs(variation*10);
    
    if (variation > 0) {
      //turn left
      setMotorsBasic(-motorSpeed, motorSpeed);
    }
    if (variation < 0) {
      //turn right
      setMotorsBasic(motorSpeed, -motorSpeed);
    }
    if (variation == 0) {
      setMotors(0,0,0);
      delay(50);
      if (getVariation(degree) == 0) {
        turning = false;
      }
    }
  }
}
