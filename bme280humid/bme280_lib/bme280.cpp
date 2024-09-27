#include "BME280Sensor.h"

BME280Sensor::BME280Sensor() : initialized(false) {}

// start sensor BME280 dengan alamat I2C
bool BME280Sensor::begin(uint8_t address) {
    if (bme.begin(address)) {
        initialized = true;
        return true;
    }
    return false;
}

// membaca suhu dari sensor
float BME280Sensor::readTemperature() {
    if (initialized) {
        return bme.readTemperature();
    } else {
        return NAN; // Return Not-A-Number if sensor is not initialized
    }
}

// membaca tekanan udara dari sensor
float BME280Sensor::readPressure() {
    if (initialized) {
        return bme.readPressure() / 100.0F; // Convert Pa to hPa
    } else {
        return NAN;
    }
}
// membaca kelembapan dari sensor
float BME280Sensor::readHumidity() {
    if (initialized) {
        return bme.readHumidity();
    } else {
        return NAN;
    }
}