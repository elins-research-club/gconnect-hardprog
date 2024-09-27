#include "BME280Sensor.h"

BME280Sensor::BME280Sensor() : initialized(false) {}

bool BME280Sensor::begin(uint8_t address) {
    if (bme.begin(address)) {
        initialized = true;
        return true;
    }
    return false;
}

float BME280Sensor::readTemperature() {
    if (initialized) {
        return bme.readTemperature();
    } else {
        return NAN; // Return Not-A-Number if sensor is not initialized
    }
}

float BME280Sensor::readPressure() {
    if (initialized) {
        return bme.readPressure() / 100.0F; // Convert Pa to hPa
    } else {
        return NAN;
    }
}

float BME280Sensor::readHumidity() {
    if (initialized) {
        return bme.readHumidity();
    } else {
        return NAN;
    }
}