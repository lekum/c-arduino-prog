/*
   Servos firmware provides a control for 3 servos using the library Servo.

   Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA

   This code is related to the book "C programming for Arduino" written by Julien Bayle
   and published by Packt Publishing.

http://cprogrammingforarduino.com

 */

#include <Servo.h> 

Servo servo01;
Servo servo02;
Servo servo03;

int angle;

void setup() 
{ 
    servo01.attach(9);
    servo02.attach(10);
    servo03.attach(11);
} 

void loop() 
{ 
    for(angle = 0; angle < 180; angle += 1)   
    {                                  
        servo01.write(angle);
        servo02.write(135-angle/2);
        servo03.write(180-angle);

        delay(15);                       
    }
}


