/*
  One_REB_LED Program cycles an RGB LED Common Cathode into each state possible
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

int pinR = 4; // pin related to Red of RGB LED
int pinG = 3; // pin related to Green of RGB LED
int pinB = 2; // pin related to Blue of RGB LED

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop()
{
  for (int r = 0 ; r < 2 ; r++)
  {
    for (int g = 0 ; g < 2 ; g++)
    {
      for (int b = 0 ; b < 2 ; b++)
      {
        digitalWrite(pinR,r); // turning red pin to value r
        digitalWrite(pinG,g); // turning green pin to value g
        digitalWrite(pinB,b); // turning blue pin to value b
        delay(150); // pausing a bit
      }
    }
  }
}
