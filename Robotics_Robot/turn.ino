void turn(int degree) {
  bool turning = true;
  while (turning) {
    int variation = getVariation(degree);
    Serial.println(variation);
    int motorSpeed = abs(variation*4);
    if (motorSpeed > 255) {
      motorSpeed = 255;
    }
    if (motorSpeed < 65) {
      motorSpeed = 65;
    }
    
    if (variation > 0) {
      //turn left
      setMotorsBasic(-motorSpeed, motorSpeed);
    }
    if (variation < 0) {
      //turn right
      setMotorsBasic(motorSpeed, -motorSpeed);
    }
    if (abs(variation) <= 2) {
      setMotors(0,0,0);
      delay(25);
      if (abs(getVariation(degree)) <= 2) {
        turning = false;
        setMotors(0,0,0);
      }
    }
  }
}
