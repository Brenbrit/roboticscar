int getDistanceIn() {
  
  long duration;
  int distance;
  
  
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
  distance= duration*0.0133/2;
  // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.print("raw, ");
  if (distance < maxDistance && distance > minDistance) {
   Serial.print(distance);
   Serial.println("reported");
   return(distance); 
  }
  }
