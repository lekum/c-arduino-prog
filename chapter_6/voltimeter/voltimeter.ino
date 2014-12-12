int potPin = 0; // pin number where the potentiometer is connected
int ledPin = 13 ; // pin number of the on-board LED
int potValue = 0 ; // variable storing the voltage value measured at potPin pin
float voltageValue = 0.; // variable storing the voltage calculated

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    potValue = analogRead(potPin);
    digitalWrite(ledPin, HIGH);
    delay(potValue);
    digitalWrite(ledPin, LOW);
    delay(potValue);
    voltageValue = 5. * (potValue / 1023.) ;
    Serial.println(voltageValue);
}
