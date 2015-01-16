/*
 readWriteI2C firmware reads and writes data to an EEPROM wired to Arduino.
 
 The EEPROM 24LC256 is wired to SDA/SCL specific pins of Arduino board.
 Please check these pins according to the model of your board.
 
 Written by Julien Bayle, this example code is in the public domain
 
 This code is related to the book "C programming for Arduino" written by Julien Bayle
 and published by Packt Publishing.
 
 http://cprogrammingforarduino.com
 
 */
 
#include <Wire.h>

void eepromWrite(byte address, byte from_address, byte data)
{
    Wire.beginTransmission(address);
    Wire.write(from_address);
    Wire.write(data);
    Wire.endTransmission();
}

byte eepromRead(int address, int from_address)
{
    Wire.beginTransmission(address);
    Wire.write(from_address);
    Wire.endTransmission();

    Wire.requestFrom(address, 1);
    if (Wire.available())
    {
        return Wire.read();
    }
    else
    {
        return 0xFF;
    }
}

void setup()
{
    Wire.begin();
    Serial.begin(9600);

    for(int i = 0; i < 10; i++) {
        eepromWrite(B01010000, i, 'a'+i);
        delay(100);
    }

    Serial.println("Bytes written to external EEPROM !");
}

void loop()
{
    for(int i = 0; i < 10; i++) {
        byte val = eepromRead(B01010000, i);
        Serial.print(i);
        Serial.print("\t");
        Serial.print(val);
        Serial.print("\n");
        delay(1000);
    }
}
