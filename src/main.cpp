#include <Arduino.h>
#include <WiFi.h>
#include <WiFiCredentials.h>
#include <HTTPClient.h>

const int sensorGPIO = 36;
const char* ssid = SSID;
const char* senha = SENHA;

int valorSensor = 0;

void conectarWifi(void) {
    WiFi.begin(ssid, senha);
    Serial.println("Conectando");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println(".");
    }
    Serial.println("Wifi conectado");
}

void setup() {
    Serial.begin(9600);
    conectarWifi();
}

void loop() {
    // valorSensor = analogRead(sensorGPIO);
    // // Serial.println(valorSensor);
    // // delay(100);
}
