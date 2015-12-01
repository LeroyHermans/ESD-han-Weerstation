/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

byte sensorValues[] = "00000";
const int messageLength = sizeof(sensorValues) / sizeof(sensorValues[0]);


void setup() {
  Serial.begin(9600);
   buttonControlSetup();
  ldrControlSetup();
  //  ledControlSetup();
  potControlSetup();
  ptcControlSetup();
}

void loop() {
  sensorValues[0] = ldrControlReadLux(0) >> 8; //high byte
  sensorValues[1] = ldrControlReadLux(0);//low byte
  sensorValues[2] = ptcControlReadTemp(0);
  sensorValues[3] = potControlReadPotVal(0);
  sensorValues[4] = getWindDirection();
  sensorValues[messageLength - 1] = checksum(sensorValues, messageLength);
  for (int i = 0; i < messageLength; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(",");
  }
  Serial.println("");
  //  setLedThermo(ptcControlReadTemp(0));
  delay(1000);
}
