#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)  // Standard sea-level pressure

Adafruit_BME280 bme;  // BME280 object

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Initializing BME280 sensor...");

  // Initialize at I2C address 0x76
  if (!bme.begin(0x76)) {
    Serial.println("BME280 not found! Check wiring or try address 0x77.");
    while (1);
  }

  Serial.println("BME280 initialized successfully.\n");
}

void loop() {
  float temperature = bme.readTemperature();        // °C
  float humidity    = bme.readHumidity();           // %
  float pressure    = bme.readPressure() / 100.0;   // hPa
  float altitude    = bme.readAltitude(SEALEVELPRESSURE_HPA);  // meters

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println("-----------------------------");
  delay(2000);   // Read every 2 seconds
}
