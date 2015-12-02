import processing.serial.*;

String initString;
Serial port;

void setup() {
  port = new Serial(this, "COM3", 9600);
  size(400, 400);
}

void draw() {
  background(0);
  
  fill(255);
  initString = port.readStringUntil('\n');
  println(initString);
  if (initString != null) {
    initString = trim(initString);
    
    String[] list = split(initString, ',');

    int[] dataStream = int(list);
    int[] cleanDataStream = new int[dataStream.length - 1];
      
      for(int i = 0; i < cleanDataStream.length; i++){
        cleanDataStream[i] = dataStream[i];
      }
    
    int checkSumArduino = dataStream[dataStream.length - 1];
//    if (checkSumArduino == checksum(cleanDataStream)) {
      
      text("Lux waarde: " + cleanDataStream[1], 50, 50);
      text("Temperatuur: " + cleanDataStream[2], 75, 75);
      text("Windsterkte: " + cleanDataStream[3], 100, 100);
      text("Windrichting: " + cleanDataStream[4], 125, 125);
//    }
  }
  else
  {
    text("No serial input available", 50, 50);
  }
  delay(100);
}

void serialEvent (Serial port) {
}

