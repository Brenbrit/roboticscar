//turn right again, we have passed the first obstacle and we're getting out of the way of the second one
void phase5() {
  turn(180);
  lastGoodDistance = 30;
  incrementPhase();
}
