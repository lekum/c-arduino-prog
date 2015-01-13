
/*
 StepperMotor firmware provides a control for an unipolar stepper motor.
 
 freely inspired by MotoKnob.
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

#include <Stepper.h>
#define STEPS 100

// Create an instance of stepper class
Stepper stepper(STEPS, 8, 9, 10, 11);

int counter = 0; // Store steps number since last change of direction
int multiplier = 1; // A basic multiplier

void setup() 
{ 
    stepper.setSpeed(30); // Set the speed at 30 RPM
} 

void loop()
{

    // Move randomly from at least 1 step
    stepper.step(multiplier);

    // Counting how many steps already moved
    // Then if we reach a whole turn, reset counter and go backward
    if (counter < STEPS)
    {
        counter++ ;
    }
    else
    { 
        counter = 0; 
        multiplier *= -1;
    }
}
