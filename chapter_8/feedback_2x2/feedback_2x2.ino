#include <Bounce.h> // include the (magic) Bounce library
#define BUTTON01 2// pin of the button #1
#define BUTTON02 3  // pin of the button #1
#define LED01 8
#define LED02 9

// let's instantiate the 2 debouncers with a debounce time of 7 ms
Bounce bouncer_button01 = Bounce (BUTTON01, 7);
Bounce bouncer_button02 = Bounce (BUTTON02, 7);

void setup()
{
    pinMode(BUTTON01, INPUT); // the switch pin 2 is setup as an input
    pinMode(BUTTON02, INPUT); // the switch pin 3 is setup as an input
    pinMode(LED01, OUTPUT);
    pinMode(LED02, OUTPUT);
    // the switch pin 8 is setup as an output
    // the switch pin 9 is setup as an output
}
void loop(){
    // let's update the two debouncers
    bouncer_button01.update();
    bouncer_button02.update();
    // let's read each button state, debounced!
    int button01_state = bouncer_button01.read();
    int button02_state = bouncer_button02.read();
    // let's test each button state and switch leds on or off
    if ( button01_state == HIGH )
    {
        digitalWrite(LED01, HIGH);
    }
    else
    {
        digitalWrite(LED01, LOW);
    }
    if ( button02_state == HIGH )
    {
        digitalWrite(LED02, HIGH);
    }
    else
    {
        digitalWrite(LED02, LOW);
    }
}
