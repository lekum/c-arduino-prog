/*
 * Uses the SimpleTimer.h library to provide ISR
 */

#include <SimpleTimer.h>

SimpleTimer timer;
boolean currentLEDState;
int ledPin = 13;

void setup() {
    currentLEDState = false;
    pinMode(ledPin, OUTPUT);
    timer.setInterval(120, blink);
}

void loop() {
    timer.run();
}

// A function to be executed each 120 ms

void blink() {
    if (!currentLEDState) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
    currentLEDState = !currentLEDState; // Invert the boolean
}
