#include <Servo.h>
#include <Stepper.h>
#include "motors.h"
#include "config.h"

Servo myServo;
Stepper stepper(STEPS, IN1, IN3, IN2, IN4);

void setupMotors() {
    myServo.attach(SERVO_PIN);
    stepper.setSpeed(10);
}

void moveServo(int angle) {
    myServo.write(angle);
}

void moveStepper(int steps) {
    stepper.step(steps);
}
