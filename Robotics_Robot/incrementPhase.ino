void incrementPhase() {
  //Serial.print("End of phase ");
  //Serial.print(phase);
  //Serial.print(", start of phase ");
  phase++;
  //Serial.println(phase);
  endTime = millis();
}



int phaseTime() {
  return (millis() - endTime);
}
