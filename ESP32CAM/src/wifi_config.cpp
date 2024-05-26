#include <WiFi.h>
#include "wifi_config.h"

const char* ssid = "SSID_TEST";
const char* password = "PAROLAMEA";

void initWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Se conecteaza la WI-FI...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Conectat cu succes!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}
