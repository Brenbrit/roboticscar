void setup() {
  Serial.begin(9600);
  pinMode(killPin, INPUT);

  
  //try to begin the bno sensor
  Serial.println("beginning the bno");
  bno.begin();
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.println("bno began. setting crystal now");
  bno.setExtCrystalUse(true);
  Serial.println("bno beginning completed.");

  Serial.println("Finished setup");
  phase = 1;
}

void loop() {

  doPhase(phase);


}
