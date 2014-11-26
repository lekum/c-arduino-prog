/*
 * Examples for the chapter 4
 */

#include <math.h>

int mySum(int m, int n) {
    return m + n;
}

double myExp(double x) {
    return exp(x / 2);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    int m = 0;
    int n = 0;
    for (m; m < 10; m++) {
        for (n; n < 10; n++) {
            Serial.print("mySum: ");
            Serial.println(mySum(m, n));
        }
    }
    double z = 10.0;
    Serial.print("myExp(10): ");
    Serial.println(myExp(z));
    delay(5000);
}
