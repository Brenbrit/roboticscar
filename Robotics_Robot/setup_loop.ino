void setup() {
  Serial.begin(9600);
  //try to begin the bno sensor
  Serial.println("beginning the bno");
  //bno.begin();
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(beeperPin, OUTPUT);
  Serial.println("bno began. setting crystal now");
  //bno.setExtCrystalUse(true);
  Serial.println("bno beginning completed.");
  Serial.print("finding first good distance, it is ");
  //lastGoodDistance = ((getDistanceIn() + getDistanceIn() + getDistanceIn())/3);
  lastGoodDistance = 6;
  Serial.println(lastGoodDistance);
  pinMode(2,OUTPUT);
  bno.begin();
  bno.setExtCrystalUse(true);
  phase = 1;
  Serial.print("Finished setup, starting phase ");
  Serial.println(phase);
}

void loop() {
  doPhase(phase);


}
