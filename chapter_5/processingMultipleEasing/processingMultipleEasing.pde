/**
  Multiple Easing
  Move the cursor and a weird series of particles will follow you.
  
 setup() is a function that runs only one time when you start the program
 draw() is a function that runs infinitely until you stop it
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 **/

// some declarations / definitions
int particlesNumber = 80;    // particles number
float[] positionsX = new float[particlesNumber];  // store the X-coordinates of particles
float[] positionsY = new float[particlesNumber];  // store the Y-coordinates of particles
float[] radii = new float[particlesNumber];      // store the radii of particles
float[] easings = new float[particlesNumber];     // store the easing of each particle

// setup is run one time at the beginning
void setup() {
  size(600, 600); // define the playground
  noStroke();     // define no stroke for all shapes drawn

  // for loop initializing easings & radii for all particles
  for (int i=0 ; i < particlesNumber ; i++)
  {
    easings[i] = 0.04 * i / particlesNumber;  // filling the easing array, increasing easing from first to last particles
    radii[i] = 30 * i / particlesNumber ;    // filling the radii array, increasing radius from first to last particles
  }
}

// draw is run infinitely
void draw() { 
  background(34);  // define the background color of the playground

  // let's store the current mouse position
  float targetX = mouseX;  
  float targetY = mouseY;

  // for loop across all particles
  for (int i=0 ; i < particlesNumber ; i++)
  {


    float dx = targetX - positionsX[i];    // calculate the delta between the mouse and the particle i over X-coordinates
    if (abs(dx) > 1) {                     // if this delta is bigger than 1, update the position according to the easings
      positionsX[i] += dx * easings[i];
    }


    float dy = targetY - positionsY[i];    // same for Y
    if (abs(dy) > 1) {
      positionsY[i] += dy * easings[i];
    }

    // change the color of the pencil for the particle i
    fill(255 * i / particlesNumber);

    // draw the particle i
    ellipse(positionsX[i], positionsY[i], radii[i], radii[i]);
  }
}

