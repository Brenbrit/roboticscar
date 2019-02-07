//the first time we go forward. should be 18in
void phase2() {
  //driveTo function.
  //goal distance: 18
  //angle: 0
  //base speed: 150
  //terminal speed: 50
  //slow distance: 9
  if (driveTo(25,0,120,40,25)) {
    incrementPhase();
  }
}
