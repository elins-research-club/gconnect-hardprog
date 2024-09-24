#include <HardwareSerial.h>
HardwareSerial LoRa(2); // Using UART2 on ESP32 (RX: GPIO16, TX: GPIO17)

void setup() {
  Serial.begin(115200);
  LoRa.begin(9600, SERIAL_8N1, 16, 17); // Baud rate and RX/TX pins

  Serial.println("LoRa Transmitter");
  delay(1000);
}

void loop() {
  String message = "Hello from Arduino!";
  // LoRa.println(message);
  Serial.println("Sent: " + message);
  delay(2000); // Transmit every 2 seconds
}
