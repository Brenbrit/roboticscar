void incrementPhase() {
  Serial.print("End of phase ");
  Serial.print(phase);
  Serial.print(", start of phase ");
  phase++;
  Serial.println(phase);
  setMotors(0,0,0);
  endTime = millis();
}



int phaseTime() {
  return (millis() - endTime);
}
