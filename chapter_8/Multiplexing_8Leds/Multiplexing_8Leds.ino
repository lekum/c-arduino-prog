/*
  Multiplexing_8Leds provide an easy way to control 8 Leds with only 3 Arduino Pins.

  This code provide a random shuffling of LEDs states.

  Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA

  This code is related to the book "C programming for Arduino" written by Julien Bayle
  and published by Packt Publishing.

  http://cprogrammingforarduino.com

 */

// 595 clock pin connecting to pin 4
int CLOCK_595 = 4;

// 595 latch pin connecting to pin 3
int LATCH_595 = 3;

// 595 serial data input pin connecting to pin 2
int DATA_595 = 2;

// random groove machine variables
int counter = 0;
byte LED_states = B00000000 ;

void setup()
{
  // Let's set all serial related pins as outputs
  pinMode(LATCH_595, OUTPUT);
  pinMode(CLOCK_595, OUTPUT);
  pinMode(DATA_595, OUTPUT);

  // use a seed coming from the electronic noise of the ADC
  randomSeed(analogRead(0));
}

void loop()
{

  // generate a random byte
  for (int i = 0 ; i < 8 ; i++)
  {
    bitWrite(LED_states, i, random(2));
  }

  // Put latch pin to LOW (ground) while transmitting data to 595
  digitalWrite(LATCH_595, LOW);

  // Shifting Out bits i.e. using the random byte for LEDs states
  shiftOut(DATA_595, CLOCK_595, MSBFIRST, LED_states);

  // Put latch pin to HIGH (5V) & all data are pushed to outputs
  digitalWrite(LATCH_595, HIGH);

  // each 5000 loop() execution, grab a new seed for the random function
  if (counter < 5000)
  {
    counter++;
  }
  else
  {
    randomSeed(analogRead(0));    // read a new value from analog pin 0
    counter = 0;                  // reset the counter
  }

  // make a short pause before changing LEDs states
  delay(45);
}
