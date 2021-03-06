#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup()
{
    // Initialize serial and wait for port to open:
    Serial.begin(9600);
}

void loop()
{
    // Read a byte from the current address of the EEPROM
    value = EEPROM.read(address);
    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
    // Advance to the next address of the EEPROM
    address = address + 1;
    // There are only 512 bytes of EEPROM, from 0 to 511, so if we're
    // on address 512, wrap around to address 0
    if (address == 512)
        address = 0;
    delay(500);
}
