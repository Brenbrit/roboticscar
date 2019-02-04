//this function converts two variables into real motor movement. both speeds are from 0-255
void setMotors(int driverSpeed, int passSpeed, int perfectX) {
  //increasing driver speed or decreasing passenger speed causes the bot to turn right
  //decreasing driver speed or increasing passenger speed causes the bot to turn left
  int variation = getVariation(perfectX);

  if (driverSpeed == 0 && passSpeed == 0) {
    motor1.brake();
    motor2.brake();
    return;
  }
  if (variation > 0) {
    driverSpeed = (driverSpeed - (10*variation));
  }
  if (variation < 0) {
    passSpeed = (passSpeed + (10*variation));
  }
  
  setMotorsBasic(driverSpeed, passSpeed);
}


void setMotorsBasic(int driverSpeed, int passSpeed) {
  motor1.drive(driverSpeed);
  motor2.drive(passSpeed);
}
