bool IRRead() {
  if (digitalRead(IR_PIN) == 0) { // 0 == detected!
    return true;
  }
  else return false;
}
