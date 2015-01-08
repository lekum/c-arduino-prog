/*
 vibrations firmware makes a pizeoelectric device vibrating cyclically
 from a very lower rate to its maximum rate.
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

int piezoPin = 9; 
int value = 0;  // stores the current feed value
int incdec = 1; // stores the direction of the variation

void setup()
{
}

void loop()
{
    // test current value and change the direction if required
    if (value == 0 || value == 255)
    {
        incdec *= -1;
    }
    analogWrite(piezoPin, value + incdec);
    delay(30);
}

