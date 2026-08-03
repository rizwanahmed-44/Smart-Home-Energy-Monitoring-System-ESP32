const int sensorPin = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (3.3 / 4095.0);

  Serial.print("Raw Value: ");
  Serial.print(sensorValue);

  Serial.print("   Voltage: ");
  Serial.print(voltage);

  Serial.println(" V");

  delay(500);
}