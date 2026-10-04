#include "DHT.h"

// Pin & Sensor Definitions
#define DHTPIN 4     // Digital pin connected to the DHT11 signal pin
#define DHTTYPE DHT11 // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 Sensor Test Initializing...");
  
  dht.begin();
}

void loop() {
  // Wait 2 seconds between measurements (DHT11 sampling rate limits)
  delay(2000);

  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature(); // Celsius

  // Check if any reads failed
  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Print results to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  |  Temperature: ");
  Serial.print(tempC);
  Serial.println("°C");
}
