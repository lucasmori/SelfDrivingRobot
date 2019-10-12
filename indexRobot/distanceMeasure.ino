int distanceMeasure() {
  int distance;
  int rangeCalc = 999;
  int average;
  int measure;

  distance = ultrasonic.read();

  for (int i = 0; i < rangeCalc; i++) {
    average += distance;

    if (average == 0)
    {
      i - (rangeCalc/2);
    }
    measure = average / rangeCalc;
  }
  return measure;
}
