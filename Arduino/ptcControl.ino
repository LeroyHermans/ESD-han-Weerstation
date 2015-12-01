/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int ptcPinArray[] = {1};

void ptcControlSetup() {
  for (int i = 0; i < getPtcArrayLength(); i++) {
    pinMode(ptcPinArray[i], INPUT);
  }
}

int getPtcArrayLength() {
  int arrayLength = 0;
  arrayLength = sizeof(ptcPinArray) / sizeof(ptcPinArray[0]);
  return arrayLength;
}

int getPtcValue(int pin) {
  int val = 0;
  val = analogRead(ptcPinArray[pin]);
  return val;
}

int ptcControlReadTemp(int pin) {
  int val = 0;
  val = map(getPtcValue(pin), 673, 788, 20, 28);
  return val;
}
