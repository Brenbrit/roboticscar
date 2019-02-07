//THIS IS ONLY FOR USE WITH THE MEGA


void setUpDisplay() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {22,23,24,25,26,27,28,29};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_ANODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
}

void disp(int num) {
  if (num < 10) {
    sevseg.setNumber(num);
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
  }
  if (num >= 10 && num < 20) {
    sevseg.setNumber(num-10);
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
  }
  if (num >= 20 && num < 30) {
    sevseg.setNumber(num-20);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
  }
  if (num >= 30 && num < 40) {
    sevseg.setNumber(num-30);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
  }
  if (num >= 40 && num < 50) {
    sevseg.setNumber(num-20);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
  }
  if (num > 49) {
    sevseg.setNumber(9);
    digitalWrite(30, HIGH);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
  }

  sevseg.refreshDisplay();
}
