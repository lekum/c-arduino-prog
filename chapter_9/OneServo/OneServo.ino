/*
   OneServo firmware provides a control of one servo using the library Servo.
   Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
   This code is related to the book "C programming for Arduino" written by Julien Bayle
   and published by Packt Publishing.
http://cprogrammingforarduino.com
 */

#include <Servo.h> 

Servo myServo;  // instantiate the Servo object
int angle = 0;    // store the current angle

void setup() 
{ 
    myServo.attach(9);  // attached the pin 9 to Servo object myServo
} 


void loop() 
{ 
    for(angle = 0; angle < 180; angle += 1)   
    {                                  
        myServo.write(angle);               
        delay(15);                       
    } 
    for(angle = 180; angle >= 1; angle -=1)     
    {                                
        myServo.write(angle);              
        delay(15);                       
    } 
}
