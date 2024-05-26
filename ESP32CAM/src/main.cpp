#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP_Mail_Client.h>
#include "wifi_config.h"
#include "email_config.h"

void setup() {
    Serial.begin(115200);
    Serial1.begin(9600, SERIAL_8N1, 16, 17); // RX = 16, TX = 17

    initWiFi();
    initEmail();

    smtp.setLogin(SMTP_HOST, SMTP_PORT, AUTHOR_EMAIL, AUTHOR_PASSWORD);
    smtp.setSender("ESP32-CAM", AUTHOR_EMAIL);
    smtp.setPriority("High");
    smtp.setSubject("Dog Water Consumption Alert");
    smtp.setMessage("This is the message content", false);
    smtp.addRecipient("Recipient", RECIPIENT_EMAIL);
}

void loop() {
    if (Serial1.available()) {
        String data = Serial1.readStringUntil('\n');
        Serial.println(data);

        // se trimite email cu datele primite
        sendEmail(data);
    }
}
