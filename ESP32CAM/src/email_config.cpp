#include <ESP_Mail_Client.h>
#include "email_config.h"

SMTPSession smtp;

void initEmail() {
    // Setare login pentru SMTP
    smtp.setLogin(SMTP_HOST, SMTP_PORT, AUTHOR_EMAIL, AUTHOR_PASSWORD);

    // Configurații suplimentare SMTP
    smtp.setClientSecure();
    smtp.setSTARTTLS(true);
    
    // Setări pentru email
    smtp.setSender("ESP32-CAM", AUTHOR_EMAIL);
    smtp.setPriority("High");
}

void sendEmail(String message) {
    SMTP_Message email;
    email.sender.name = "ESP32-CAM";
    email.sender.email = AUTHOR_EMAIL;
    email.subject = "Alerta: Cainele a baut apa";
    email.message.text = message.c_str();
    email.addRecipient("Recipient", RECIPIENT_EMAIL);

    smtp.debug(1);
    if (!MailClient.sendMail(&smtp, &email)) {
        Serial.println("Error sending Email, " + smtp.errorReason());
    }
}
