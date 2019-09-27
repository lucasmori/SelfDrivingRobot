void moveServo(int posicao) {
  int pos = 0;

  if (posicao == 180) {
    for (pos = 90; pos <= 179; pos += 1) { // vai de 90 até 180 graus
      // in steps of 1 degree
      servo.write(pos);
      delay(15);
    }
  }

  if (posicao == 90) {
    for (pos = 179; pos >= 90; pos -= 1) { // vai de 180 para 90 graus
      servo.write(pos);
      delay(15);
    }
  }

  if (posicao == 0) {
    for (pos = 90; pos >= 0; pos -= 1) { // vai de 0 para 90 graus
      servo.write(pos);
      delay(15);
    }
  }
}
