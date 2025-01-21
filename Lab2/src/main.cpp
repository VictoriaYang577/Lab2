#include <Arduino.h>

// Constants
const int ANALOG_PIN = A1;
const float REFERENCE_VOLTAGE = 3.3;

// Function declarations
void initializeSerial();
void printAnalogReadings();

void setup() {
  initializeSerial();
  analogReadResolution(12); // Set analog read resolution to 12 bits
}

void loop() {
  printAnalogReadings();
  delay(500);
}

// Initialize Serial communication
void initializeSerial() {
  Serial.begin(115200);
  while (!Serial) {
    // Wait for Serial connection
  }
  Serial.println("Serial communication initialized.");
}

// Read and print analog values and corresponding voltage
void printAnalogReadings() {
  int analogValue = analogRead(ANALOG_PIN);
  float voltage = (analogValue / 4095.0) * REFERENCE_VOLTAGE;

  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.println(" V");
}