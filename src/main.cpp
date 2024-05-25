#include <Arduino.h>

const int sensorGPIO = 36;
int valorSensor = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    valorSensor = analogRead(sensorGPIO);
    Serial.println(valorSensor);
    delay(100);
}
