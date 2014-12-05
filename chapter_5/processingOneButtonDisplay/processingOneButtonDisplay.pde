import processing.serial.*;

Serial theSerialPort;
int[] serialBytesArray = new int[2];
int switchID;
int switchState;
int bytesCount = 0;
boolean init = false;
int fillColor = 40; 			// Defining the initial fill color

void setup()
{

  size(500, 500);
  background(70);
  noStroke();

  // Printing the list of all serial devices (debug purpose)
  println(Serial.list());
  // Let's assume the Arduino is the first one
  String thePortName = Serial.list()[0];
  theSerialPort = new Serial(this, thePortName, 9600);
}

void draw()
{
  fill(fillColor);
  // Draw a circle in the middle of the screen
  ellipse(width/2, height/2, 230, 230);
}

void serialEvent(Serial myPort)
{
  // Read a byte from the serial port
  int inByte = myPort.read();

  // If this is the first hello
  if (init == false)
  {
    if (inByte == 'Z')
    {
      myPort.clear(); // Clear the serial port buffer
      init = true;
      myPort.write('Z'); // Tell the Arduino to send more
    }
  } else
  {
    // Add the latest byte form the serial port to an array
    serialBytesArray[bytesCount] = inByte;
    bytesCount++;

    if (bytesCount > 1)
    {
      switchID = serialBytesArray[0];
      switchState = serialBytesArray[1];
      println(switchID + "\t" + switchState);

      if (switchState == 0)
      {
        fillColor = 40;
      } else
      {
        fillColor = 255;
      }

      // Request new sensor readings
      myPort.write('Z');
      bytesCount = 0;
    }
  }
}

