#ifndef EMAIL_CONFIG_H
#define EMAIL_CONFIG_H

#include <ESP_Mail_Client.h>

extern SMTPSession smtp;

void initEmail();
void sendEmail(String message);

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "your_email@gmail.com"
#define AUTHOR_PASSWORD "your_email_password"
#define RECIPIENT_EMAIL "recipient_email@example.com"

#endif
