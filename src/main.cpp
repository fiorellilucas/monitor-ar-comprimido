#include <Arduino.h>
#include <WiFi.h>
#include <ConstantesPrivadas.h>
#include <HTTPClient.h>

const int sensor_gpio = 36;
int valor_sensor = 0;

void conectar_wifi(void) {
    WiFi.begin(SSID, SENHA);
    Serial.println("Conectando");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println(".");
    }
    Serial.println("Wifi conectado");
}

void setup() {
    Serial.begin(9600);
    conectar_wifi();
}

void loop() {
    // valor_sensor = analogRead(sensor_gpio);
    // // Serial.println(valor_sensor);
    // // delay(100);
}
