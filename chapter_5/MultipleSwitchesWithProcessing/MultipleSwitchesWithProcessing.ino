/*
  MultiSwitchWithProcessing is a small program detecting when you push buttons or not
 and working with processing.
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

#define switchesNumber 3             // define the number of buttons as a constant

int switchesStates[switchesNumber] ; // array storing current switches states
int lastSwitchesStates[switchesNumber] ; // array storing last switches states
int inByte = 0;
// variables related to the debouncing system
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  Serial.begin(9600);

  // initiating each pins as input and filling switchesStates with zeroes
  for(int i = 0 ; i < switchesNumber ; i++)
  {
    
    pinMode(i+2, INPUT); // the switch pin i+2 is setup as an input
    
    switchesStates[i] = 0 ;
    lastSwitchesStates[i] = LOW;
  }

  sayHello();                      // waiting for the processing program hello answer
}

void loop(){

  // if a valid byte is received from processing, read all digital inputs.
  if (Serial.available() > 0) {

    // get incoming byte
    inByte = Serial.read();

    for(int i = 0 ; i < switchesNumber ; i++)
    {
      int readInput = digitalRead(i+2);
      if (readInput != lastSwitchesStates[i])
      {
          // Reset the debounce counter by storing the current uptime in ms
          lastDebounceTime = millis();
      }
      if ( (millis() - lastDebounceTime) > debounceDelay)
      {
          // Store the value because it is a debounced one
          switchesStates[i] = readInput;
      }
      
      Serial.write(i);                 // send the 1st byte with the switch number from 0 to 2 here.
      Serial.write(switchesStates[i]); // send the bytes with the switch i state
    }
  }
}

void sayHello() {
  while (Serial.available() <= 0) {
    Serial.print('Z');   // send a capital Z to Arduino to say "HELLO!"
    delay(200);
  }
}
