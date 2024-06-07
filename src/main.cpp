#include <Arduino.h>
#include <WiFi.h>
#include <ConstantesPrivadas.h>
#include <HTTPClient.h>
#include <esp_adc_cal.h>

const int sensor_gpio = 36;
int valor_sensor = 0;
uint32_t valor_sensor_cal = 0;

void conectar_wifi(void) {
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

uint32_t ler_sensor_cal(int valor_sensor) {
    esp_adc_cal_characteristics_t caract_adc;
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_11db, ADC_WIDTH_12Bit, 1100, &caract_adc);
    
    return (esp_adc_cal_raw_to_voltage(valor_sensor, &caract_adc));
}

void setup() {
    Serial.begin(9600);
    conectar_wifi();
}

void loop() {
    valor_sensor = analogRead(sensor_gpio);
    valor_sensor_cal = ler_sensor_cal(valor_sensor);

    fazer_request(valor_sensor_cal);

    delay(1000);
}
