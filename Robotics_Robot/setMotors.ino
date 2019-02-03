//this function converts two variables into real motor movement. both speeds are from 0-255
void setMotors(int driverSpeed, int passSpeed, int perfectX) {
  
  
  setMotorsBasic(driverSpeed, passSpeed);
}


void setMotorsBasic(int driverSpeed, int passSpeed) {
  motor1.drive(driverSpeed);
  motor2.drive(passSpeed);
}
