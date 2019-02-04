int getVariation(int ideal) {
  //just getting some stuff for the sensor
  sensors_event_t event;
  bno.getEvent(&event);

  int real = event.orientation.x;

  if (ideal >= 180) {
    if (real > ideal) {
      //the ideal is above 180, and the real is somewhere between 180 and 360. easy
      return(real-ideal);
    }
    if (real < ideal) {
      if ((ideal-real) < 180) {
        //ideal is greater than 180 and real is less than 180 fewer than that.
        return (real-ideal);
      } else {
        //more complicated. 
        return (360 - ideal + real);
      }
    }
  } else {
    //the ideal is less than or equal to 180
    if (real <= ideal) {
      //easy. real is less than ideal and ideal is less than 180. real < ideal < 180
      return (-ideal + real);
    } else {
      if ((real-ideal) < 180) {
        return (real - ideal);
      } else {
        //complicated. Real is more than 180 greater than ideal. 
        return (-(360-real+ideal));
      }
    }
  }
}
