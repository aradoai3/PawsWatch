#include <Arduino.h>
#include "sensors.h"
#include "display.h"
#include "motors.h"
#include "config.h"

unsigned long lastDrinkTime = 0;
unsigned long elapsedTime = 0;
bool dogDrank = false;

void updateLCD() {
    updateDisplay(dogDrank, lastDrinkTime);
}

void setup() {
    Serial.begin(9600);
    setupSensors();
    setupDisplay();
    setupMotors();

    Timer1.initialize(1000000); // setare timer pentru 1 secundă (1,000,000 microsecunde)
    Timer1.attachInterrupt(updateLCD); // atașează funcția de întrerupere pentru actualizare LCD
}

void loop() {
    float distance = readUltrasonic();
    if (distance < 20) { // dacă câinele se apropie
        moveServo(90); // se mișcă servomotorul
        delay(1000);
        moveServo(0);
        delay(1000);

        int waterLevel = readWaterLevel();
        if (waterLevel < 500) { // pragul de nivel al apei
            moveStepper(STEPS / 4); // mișcă motorul care actioneaza recipientul cu apa
            delay(1000);
            moveStepper(-STEPS / 4); // revine la poziția inițială
            lastDrinkTime = millis(); // actualizează timpul ultimei dati cand a baut
            dogDrank = true;
        }
    }
}
