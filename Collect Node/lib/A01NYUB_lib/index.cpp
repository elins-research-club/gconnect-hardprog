#include "a01nyub_sensor.h"

A01NYUBSensor::A01NYUBSensor(int trigger, int echo) 
    : triggerPin(trigger), echoPin(echo) {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float A01NYUBSensor::getDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    return duration * 0.0343 / 2;
}