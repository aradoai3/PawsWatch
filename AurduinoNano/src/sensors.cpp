#include <NewPing.h>
#include <DHT.h>
#include "sensors.h"
#include "config.h"

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
DHT dht(DHTPIN, DHTTYPE);

void setupSensors() {
    dht.begin();
}

float readUltrasonic() {
    unsigned int uS = sonar.ping();
    return uS / US_ROUNDTRIP_CM;
}

float readTemperature() {
    return dht.readTemperature();
}

float readHumidity() {
    return dht.readHumidity();
}

int readWaterLevel() {
    return analogRead(WATER_SENSOR_PIN);
}
