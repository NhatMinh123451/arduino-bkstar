#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <LiquidCrystal_I2C.h>

#define SEALEVELPRESSURE_HPA (1013.25)

// Create BME280 object
Adafruit_BME280 bme;

// Create LCD object (I2C address 0x27, 16x2 display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("BME280 + LCD");
  delay(1500);
  lcd.clear();

  // Initialize BME280 sensor
  if (!bme.begin(0x76)) {
    lcd.print("BME Err!");
    while (1);  // Stop execution
  }
}

void loop() {
  float temp = bme.readTemperature();          // °C
  float humidity = bme.readHumidity();         // %
  float pressure = bme.readPressure() / 100.0; // hPa
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA); // meters

  // --- Line 1: Temperature + Humidity ---
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp, 1);  
  lcd.print("C ");

  lcd.print("H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  // --- Line 2: Pressure + Altitude ---
  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(pressure, 0);
  lcd.print("h ");

  lcd.print("A:");
  lcd.print(altitude, 0);  // altitude in meters

  delay(1500);
}