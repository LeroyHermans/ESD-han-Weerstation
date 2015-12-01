/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int potPinArray[] = {0};

void potControlSetup() {
  for (int i = 0; i < getPotArrayLength(); i++) {
    pinMode(potPinArray[i], INPUT);
  }
}

int getPotArrayLength() {
  int arrayLength = 0;
  arrayLength = sizeof(potPinArray) / sizeof(potPinArray[0]);
  return arrayLength;
}

int getPotValue(int pin) {
  int val = 0;
  val = analogRead(potPinArray[pin]);
  return val;
}

int potControlReadPotVal(int pin) {
  int val = 0;
  val = map(getPotValue(pin), 1024, 0, 0, 99);
  return val;
}
