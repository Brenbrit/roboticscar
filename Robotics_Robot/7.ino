//turn left to move past the 2nd set of obstacles. We need to be careful here, this relies on a single obstacle for distance.
void phase7() {
  turn(90);
  lastGoodDistance = 6;
  incrementPhase();
}
