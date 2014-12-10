import processing.serial.*;

int switchesNumber = 2;

Serial theSerialPort;                 // create the serial port object
int[] serialBytesArray = new int[2];  // array storing current message
int switchID;                         // index of the switch
int[] switchesStates = new int[switchesNumber]; // current switch state
int bytesCount = 0;                   // current number of bytes relative to messages
boolean init = false;                 // init state
int fillColor = 40;                   // defining the initial fill color

// circles display stuff
int distanceCircles ;
int radii;

void setup() {

  // define some canvas and drawing parameters
  size(500, 500);
  background(70);
  noStroke();
  distanceCircles = width / switchesNumber;
  radii = distanceCircles/2;

  // printing the list of all serial devices (debug purpose)
  println(Serial.list());

  // On osx, the Arduino port is the first into the list
  String thePortName = Serial.list()[0];

  // Instantate the Serial Communication
  theSerialPort = new Serial(this, thePortName, 9600);

  for (int i = 0 ; i < switchesNumber ; i++)
  {
    switchesStates[i] = 0;
  }
}

void draw() {

  for (int i = 0 ; i < switchesNumber ; i++)
  {
    if (switchesStates[i] == 0) fill(0);
    else fill(255);

    // draw a circle in the middle of the screen
    ellipse(distanceCircles * (i + 1) - radii, height/2, radii, radii);
  }
}


void serialEvent(Serial myPort) {

  // read a byte from the serial port
  int inByte = myPort.read();

  if (init == false) {         // if this is the first hello
    if (inByte == 'Z') {       // if the byte read is Z
      myPort.clear();          // clear the serial port buffer
      init = true;             // store the fact we had the first hello
      myPort.write('Z');       // tell the Arduino to send more !
    }
  } 
  else {                       // if there already was the first hello

    // Add the latest byte from the serial port to array
    serialBytesArray[bytesCount] = inByte;
    bytesCount++;

    // if the messages is 2 bytes length
    if (bytesCount > 1 ) {
      switchID = serialBytesArray[0];      // store the ID of the concerned switch
      switchesStates[switchID] = serialBytesArray[1];   // store the state of the switch

      // print the values (for debugging purposes):
      println(switchID + "\t" + switchesStates[switchID]);

      // Send a capital Z to request new sensor readings
      myPort.write('Z');

      // Reset bytesCount:
      bytesCount = 0;
    }
  }
}
