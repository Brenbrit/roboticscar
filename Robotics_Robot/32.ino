void phase32() {
  //we're at the end, bois
  beep(200,4);
  //and finally, we delay forever.
  while(true) {
    Serial.println("we done bois");
    delay(1000);
  }
}
