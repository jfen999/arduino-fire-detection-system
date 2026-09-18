/*
  Arduino Fire Detection System

  Connections:
  - Flame sensor DO -> D7
  - DHT22 DATA -> D2
  - I2C LCD SDA -> A4
  - I2C LCD SCL -> A5

  The LCD displays temperature, humidity, and the current
  fire status. Sensor readings are also printed to the
  Serial Monitor for testing and debugging.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

const int FLAME_SENSOR_PIN = 7;
const int DHT_PIN = 2;
const int DHT_TYPE = DHT22;
const int LCD_ADDRESS = 0x27;

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);

void setup() {
  Serial.begin(9600);

  pinMode(FLAME_SENSOR_PIN, INPUT);

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.println("Arduino Fire Detection System");
  Serial.println("System started");
  Serial.println();
}

void loop() {
  // Read the sensors
  int flameState = digitalRead(FLAME_SENSOR_PIN);
  float humidity = dht.readHumidity();
  float temperatureF = dht.readTemperature(true);

  // Make sure the DHT22 returned valid readings
  if (isnan(humidity) || isnan(temperatureF)) {
    Serial.println("DHT22 read failed. Check wiring.");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: Error");

    lcd.setCursor(0, 1);
    lcd.print("Check DHT22");

    lcd.setCursor(0, 2);
    lcd.print("Humidity: Error");

    delay(2000);
    return;
  }

  lcd.clear();

  // Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureF, 1);
  lcd.print((char)223);
  lcd.print("F");

  // Flame sensor is active LOW
  lcd.setCursor(0, 1);
  if (flameState == LOW) {
    lcd.print("FLAME ALERT");
  } else {
    lcd.print("SAFE");
  }

  // Humidity
  lcd.setCursor(0, 2);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  // Print readings to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.print("% | Temperature: ");
  Serial.print(temperatureF, 1);
  Serial.print(" F | Flame sensor: ");

  if (flameState == LOW) {
    Serial.println("FLAME ALERT");
  } else {
    Serial.println("SAFE");
  }

  delay(2000);
}
