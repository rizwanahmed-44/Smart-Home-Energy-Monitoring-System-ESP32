const int sensorPin = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (3.3 / 4095.0);

  // Simulated current (0–5 A)
  float current = sensorValue * (5.0 / 4095.0);

  float power = voltage * current;

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V");

  Serial.print("   Current: ");
  Serial.print(current);
  Serial.print(" A");

  Serial.print("   Power: ");
  Serial.print(power);
  Serial.println(" W");

  delay(500);
}