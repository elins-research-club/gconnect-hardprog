#include <HardwareSerial.h>
HardwareSerial LoRa(1); // Using UART1 on ESP32-S3 (RX: GPIO15, TX: GPIO16)

void setup() {
  Serial.begin(115200);
  LoRa.begin(9600, SERIAL_8N1, 15, 16); // Baud rate and RX/TX pins

  Serial.println("LoRa Receiver");
}

void loop() {
  // Serial.println("loopingggg");
  if (LoRa.available()) {
    String receivedMessage = LoRa.readString();
    Serial.println("Received: " + receivedMessage);
  }
  delay(500);
}
