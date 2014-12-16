/*
 * Sktech to read to 8 analog inputs via the mux/demux CD4051B
 */

int muxOutputPin = 0 ;  // pin connected to the common output of the CD4051B
int devicesNumber = 8 ; // number of device // BE CAREFUL, plug them from 0

int controlPinA = 2 ;   // pin connected to the select pin A of the CD4051B
int controlPinB = 3 ;   // pin connected to the select pin B of the CD4051B
int controlPinC = 4 ;   // pin connected to the select pin C of the CD4051B

int currentInput = 0 ;  // hold the current analog input commuted o the common output of the CD4051B

void setup()
{
    Serial.begin(9600);

    // setting up all 3 digital pins related to selectors A, B and C as outputs
    pinMode(controlPinA, OUTPUT);
    pinMode(controlPinB, OUTPUT);
    pinMode(controlPinC, OUTPUT);
}

void loop(){
    for (currentInput = 0 ; currentInput < devicesNumber - 1 ; currentInput++)
    {
    // selecting the inputs that is commuted to the common output of the CD4051B
        digitalWrite(controlPinA, bitRead(currentInput,0));
        digitalWrite(controlPinB, bitRead(currentInput,1));
        digitalWrite(controlPinC, bitRead(currentInput,2));

        // reading and storing the value of the currentInput
        Serial.println(analogRead(muxOutputPin));
    }
}
