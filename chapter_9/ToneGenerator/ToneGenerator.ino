/*
 ToneGenerator firmware play a random melody over a speaker.
 
 Written by Julien Bayle, this example code is in the public domain
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

void setup()
{
  // Initiate the pseudo-random number generator
  randomSeed(analogRead(0));
}

void loop()
{

  // Generate random pitch & duration
  int pitch = random(30,5000);
  int duration = 1000 / (random(1000) + 1);

  // Play a tone to the diital pin PWM number 8
  tone(8, pitch, duration);

  // Make a pause
  delay(duration * 1.30);

  // Stop the tone playing
  noTone(8);
}
