#include <Arduino.h>
#include <WiFi.h>
#include <ConstantesPrivadas.h>
#include <HTTPClient.h>

#define SENSOR_GPIO 36

int valor_sensor;

void conectar_wifi(void)
{
    WiFi.begin(SSID, SENHA);
    Serial.println("Conectando");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println(".");
    }
    Serial.print("Wifi conectado, IP do ESP32: ");
    Serial.println(WiFi.localIP());
}

void setup()
{
    Serial.begin(9600);
    conectar_wifi();

    WiFiClientSecure client;

    client.setCACert(CERTIFICADO_SSL);

    if (client.connect(URL_SERVER_API_NGROK, 443)) {
        Serial.println("Conectado ao servidor");
    }
}

void loop()
{
    valor_sensor = analogRead(SENSOR_GPIO);
    Serial.println(valor_sensor);
    delay(100);

    // if (WiFi.status() == WL_CONNECTED)
    // {

    // }
}
