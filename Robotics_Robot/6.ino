//we are turning to face the right wall after passing the first set of obstacles.
void phase6() {
  setMotors(0,0,0);
  turn(180);
  incrementPhase();
}
