#include <./lib/Gsoil_lib/Gsoil_lib.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include <TaskScheduler.h>

// Pin Definitions
#define SOIL_PIN 34

float wind_speed = 0;
float temperature = 0;
float humidity = 0;
float soil_moisture = 0;
float rainfall_rate = 0;
float water_level = 0;
double longitude = 0;
double latitude = 0;
int16_t accel_x = 0;
int16_t accel_y = 0;
int16_t accel_z = 0;

HardwareSerial LoRa(2);  // Using UART2 on ESP32 (RX: GPIO16, TX: GPIO17)

Scheduler scheduler;

Task task1(1000, TASK_FOREVER, []() {
    soil_moisture = Soilread(SOIL_PIN);
});

// Task

Task taskSendData(2000, TASK_FOREVER, []() {
    String message = String(soil_moisture);
    LoRa.println(message);
});

void setup() {
    Serial.begin(115200);
    LoRa.begin(9600, SERIAL_8N1, 16, 17);  // Baud rate and RX/TX pins

    scheduler.addTask(task1);
    scheduler.addTask(taskSendData);

    task1.enable();
    taskSendData.enable();
}

void loop() {
    scheduler.execute();
}
