/**********************
 *  Created by: Leroy Hermans
 *  Date: 01-12-2015
 *  Version: 1.0.0
 *********************/

int checksum(int[] cleanDataStream) {
  int sum = 0;
  for (int i = 0; i < cleanDataStream.length; i++) {
    sum += cleanDataStream[i];
  }
  sum = sum - 256;
  println(sum);
  return sum;
}

