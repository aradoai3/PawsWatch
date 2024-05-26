#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"
#include "sensors.h"
#include "config.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setupDisplay() {
    lcd.begin(16, 2);
    lcd.backlight();
}

void updateDisplay(bool dogDrank, unsigned long lastDrinkTime) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastDrinkTime;
    unsigned long secondsSinceLastDrink = elapsedTime / 1000;
    unsigned long minutesSinceLastDrink = secondsSinceLastDrink / 60;
    secondsSinceLastDrink = secondsSinceLastDrink % 60;
    unsigned long hoursSinceLastDrink = minutesSinceLastDrink / 60;
    minutesSinceLastDrink = minutesSinceLastDrink % 60;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    float t = readTemperature();
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    float h = readHumidity();
    lcd.print(h);
    lcd.print("%");

    if (dogDrank) {
        lcd.setCursor(0, 1);
        lcd.print("Last drink: ");
        lcd.print(hoursSinceLastDrink);
        lcd.print("h ");
        lcd.print(minutesSinceLastDrink);
        lcd.print("m ");
        lcd.print(secondsSinceLastDrink);
        lcd.print("s");
    }

    // trimite datele către ESP32-CAM
    Serial.print(t);
    Serial.print(",");
    Serial.print(h);
    Serial.print(",");
    Serial.print(hoursSinceLastDrink);
    Serial.print(":");
    Serial.print(minutesSinceLastDrink);
    Serial.print(":");
    Serial.println(secondsSinceLastDrink);
}
