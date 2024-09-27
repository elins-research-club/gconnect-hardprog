#ifndef A01NYUB_SENSOR_H
#define A01NYUB_SENSOR_H

class A01NYUBSensor {
private:
    int triggerPin;
    int echoPin;

public:
    A01NYUBSensor(int trigger, int echo);
    float getDistance();
};

#endif