/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int ldrPinArray[] = {2};

void ldrControlSetup() {
  for (int i = 0; i < getLdrArrayLength(); i++) {
    pinMode(ldrPinArray[i], INPUT);
  }
}

int getLdrArrayLength() {
  int arrayLength = 0;
  arrayLength = sizeof(ldrPinArray) / sizeof(ldrPinArray[0]);
  return arrayLength;
}

int getLdrValue(int pin) {
  int val = 0;
  val = analogRead(ldrPinArray[pin]);
  return val;
}

int ldrControlReadLux(int pin) {
  int val = 0;
  val = map(getLdrValue(pin), 1023, 0, 255, 0);
  return val;
}

