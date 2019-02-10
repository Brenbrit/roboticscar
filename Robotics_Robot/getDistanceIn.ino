int getDistanceIn() {
  
  long duration;
  long distance;
  
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.00665;
  
  
  if (int(distance) <= maxDistance && int(distance) >= minDistance) {
    //distance meets the requirements to be valid, but is it really? We'll reject any change of >5in.
    if (abs(lastGoodDistance - distance) <= long(5)) {
      lastGoodDistance = distance;
      digitalWrite(2,LOW);
      return(int(distance));
    }
  }
  //looks like we haven't reached an answer. let's recurse
  digitalWrite(2,HIGH);
  delay(20);
  return(getDistanceIn());
}
