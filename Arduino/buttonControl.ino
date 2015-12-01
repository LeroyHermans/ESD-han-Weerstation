/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int buttonPinArray[] = {2, 3, 4, 5};

void buttonControlSetup() {
  for (int i = 0; i < getButtonArrayLength(); i++) {
    pinMode(buttonPinArray[i], INPUT);
  }
}

int getButtonArrayLength() {
  int arrayLength = 0;
  arrayLength = sizeof(buttonPinArray) / sizeof(buttonPinArray[0]);
  return arrayLength;
}

char getWindDirection() {
  char windDirection  = 0;
  for (int i = 0; i < getButtonArrayLength(); i++) {
    int pressed = 4;

    if (digitalRead(buttonPinArray[i]) == 1) {
      pressed = i;
      switch (pressed) {
        case 0:
          windDirection = 'N';
          break;
        case 1:
          windDirection = 'E';
          break;
        case 2:
          windDirection = 'S';
          break;
        case 3:
          windDirection = 'W';
          break;
        case 4:
          windDirection = 0;
          break;
      }
    }
  }
  return windDirection;
}


