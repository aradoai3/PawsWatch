#include <WiFi.h>
#include "wifi_config.h"

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

void initWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}
