import processing.serial.*;

String initString;
Serial port;

void setup() {
  port = new Serial(this, "COM3", 9600);

  size(400, 400);
}

void draw() {
  background(0);

  initString = port.readStringUntil('\n');
  delay(1000);
  println(initString);

  //  if (inistring != null){
  //    inistring = trim(inistring);
  //    
  //     String[] list = split(inistring, ",");
  //     
  //     int[] dataStream*int(list);
  //     int[] cleanDataStream*new int(datastream.length-1);
  //     println(cleanDataStream);
  //  }
  //  else{
  //    
  //  }
}

void serialEvent (Serial port) {
}

