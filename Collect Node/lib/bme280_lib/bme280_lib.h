#ifndef BME280SENSOR_H
#define BME280SENSOR_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Sensor {
public:
    BME280Sensor();
    bool begin(uint8_t address = 0x76);
    float readTemperature();
    float readPressure();
    float readHumidity();
    
private:
    Adafruit_BME280 bme;
    bool initialized;
};

#endif
