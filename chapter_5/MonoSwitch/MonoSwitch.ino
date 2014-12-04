/*
 * Sketch to light up the built-in LED (pin 13)
 * when a switch is pressed
 */

const int switchPin = 2;
const int ledPin = 13;
int switchState = 0; // Storage variable for current switch

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT);
}

void loop()
{
    switchState = digitalRead(switchPin);
    if (switchState == HIGH)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}
