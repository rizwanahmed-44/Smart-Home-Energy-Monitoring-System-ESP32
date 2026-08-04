#define BLYNK_TEMPLATE_ID "TMPL6wDaOEInx"
#define BLYNK_TEMPLATE_NAME "Smart Home Energy Monitoring System"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Analog input pins
#define VOLTAGE_PIN 34
#define CURRENT_PIN 35

void setup() {
  Serial.begin(115200);

  pinMode(VOLTAGE_PIN, INPUT);
  pinMode(CURRENT_PIN, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {

  Blynk.run();

  int voltageRaw = analogRead(VOLTAGE_PIN);
  int currentRaw = analogRead(CURRENT_PIN);

  // Convert ADC values to simulated voltage and current
  float voltage = (voltageRaw / 4095.0) * 250.0;   // 0–250 V
  float current = (currentRaw / 4095.0) * 10.0;    // 0–10 A

  // Calculate power
  float power = voltage * current;

  // Print values to Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V\t");

  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A\t");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  // Send values to Blynk
  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, power);

}
