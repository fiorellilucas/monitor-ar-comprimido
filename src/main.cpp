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

void fazer_request(int valor_sensor) {
    HTTPClient http;
    http.begin(URL_SERVER);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String valor = "sensor=" + String(valor_sensor);

    int http_code = http.POST(valor);

    if (http_code > 0) {
        if (http_code == HTTP_CODE_OK) {
            Serial.println(http.getString());
        }
        else {
            Serial.println(http_code);
        }
    }
    else {
        Serial.println(http.errorToString(http_code).c_str());
    }
    
    http.end();
}

void setup() {
    Serial.begin(9600);
    conectar_wifi();
}

void loop() {
    valor_sensor = analogRead(sensor_gpio);
    fazer_request(valor_sensor);

    delay(1000);
}
