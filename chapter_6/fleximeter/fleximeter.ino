/*
 * Sketch that measures and sends the angle of a flexi sensor
 * The sensor is a 20K resistor at 0º and 10K at 90º
 * Can be lineary approximated
 * The circuit is a voltage divider with another resistor of 20K
 */

int sensorValue = 0;
int sensorPin = 12;
int angleCalculated = 0;
int fromLow = 511;
int fromHigh = 347;
int toLow = 0;
int toHigh = 90;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    sensorValue = analogRead(sensorPin);
    angleCalculated = map(sensorValue, fromLow, fromHigh, toLow, toHigh);
    Serial.println(angleCalculated);
    delay(2);
}
