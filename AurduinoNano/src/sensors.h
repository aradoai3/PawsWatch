#ifndef SENSORS_H
#define SENSORS_H

void setupSensors();
float readUltrasonic();
float readTemperature();
float readHumidity();
int readWaterLevel();

#endif
