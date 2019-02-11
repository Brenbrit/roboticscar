//turn right after going forward for the first time
void phase3() {
  disp(0);
  turn(90);
  lastGoodDistance = 3;
  firstDistance = getDistanceIn();
  firstDistanceTime = millis();
  incrementPhase();
}
