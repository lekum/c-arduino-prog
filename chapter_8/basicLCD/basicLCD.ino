/*
 basicLCD display some messages on an Hitachi HD44780 driver compatible LCD 
 
 This example uses the Core library LiquidCrystal
 
 Written by Julien Bayle, this example code is under Creative Commons CC-BY-SA
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */

#include <LiquidCrystal.h>

String manyMessages[4];
int counter = 0;

// Initialize the library with pins number of the circuit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{

  // set up the number of column and row of the LCD
  lcd.begin(16, 2);

  manyMessages[0] = "I am the Arduino";
  manyMessages[1] = "I can talk";
  manyMessages[2] = "I can feel";
  manyMessages[3] = "I can react";
  
  // shaking the dice!
  randomSeed(analogRead(0));
}

void loop()
{

  // set the cursor to column 0 and row 0
  lcd.setCursor(0, 0);

  // each 5s
  if (millis() - counter > 5000)
  {
    lcd.clear(); // clear the whole LCD
    lcd.print(manyMessages[random(4)]); // display a random message
    counter = millis();  // store the current time
  }

  // set the cursor to column 0 and row 1
  lcd.setCursor(0, 1);
  // print the value of millis() at each loop() execution
  lcd.print("up since: " + String(millis()) + "ms");
}
