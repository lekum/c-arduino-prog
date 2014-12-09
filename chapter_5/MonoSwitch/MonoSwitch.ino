/*
 * Sketch to light up the built-in LED (pin 13)
 * when a switch is pressed
 */

const int switchPin = 2;
int switchState = 0; // Storage variable for current switch
int inByte = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(switchPin, INPUT);
    sayHello();
}

void loop()
{
    if (Serial.available() > 0)
    {
        // If a valid byte is received from processing,
        // read the digital in
        inByte = Serial.read();
        switchState = digitalRead(switchPin);

        // Send switch state to Arduino
        Serial.write("0");
        Serial.write(switchState);
    }
}

void sayHello()
{
    while (Serial.available() <= 0)
    {
        Serial.print('Z'); // Send a capital Z to Arduino to say "HELLO!"
        delay(200);
    }
}
