/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int checksum(byte sensorValue[], int messageLength) {
  int sum = 0;
  for (int i = 0; i < (messageLength - 1); i++) {
    sum += sensorValue[i];
  }
  return sum;
}

