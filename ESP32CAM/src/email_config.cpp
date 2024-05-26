#include <ESP_Mail_Client.h>
#include "email_config.h"

SMTPSession smtp;

void initEmail() {
    // Configurații suplimentare, dacă este necesar
}

void sendEmail(String message) {
    SMTP_Message email;
    email.sender.name = "ESP32-CAM";
    email.sender.email = AUTHOR_EMAIL;
    email.subject = "Dog Water Consumption Alert";
    email.message.text = message.c_str();
    email.addRecipient("Recipient", RECIPIENT_EMAIL);

    smtp.debug(1);
    if (!MailClient.sendMail(&smtp, &email)) {
        Serial.println("Error sending Email, " + smtp.errorReason());
    }
}
