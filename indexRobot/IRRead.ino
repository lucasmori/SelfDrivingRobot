bool IRRead() {
  if (digitalRead(IR_PIN) == 0) { // quando for 0 quer dizer que esta detectando a mesa
   // Serial.println("Obstaculo detectado");
    return true;
  }
  else return false;
}
