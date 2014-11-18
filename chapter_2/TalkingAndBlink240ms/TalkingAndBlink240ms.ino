/*
 TalkingAndBlink 250 ms Program
 */

int ledPin = 8;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    Serial.print("The pin ");
    Serial.print(ledPin);
    Serial.println(" is on");
    delay(250);
    digitalWrite(ledPin, LOW);
    Serial.print("The pin ");
    Serial.print(ledPin);
    Serial.println(" is off");
    delay(1000);
}
