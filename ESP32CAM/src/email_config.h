#ifndef EMAIL_CONFIG_H
#define EMAIL_CONFIG_H

#include <ESP_Mail_Client.h>

extern SMTPSession smtp;

void initEmail();
void sendEmail(String message);

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "ioanaaradoaie06@gmail.com"
#define AUTHOR_PASSWORD "PAROLAMEA"
#define RECIPIENT_EMAIL "ioana_aradoaie@yahoo.com"

#endif
