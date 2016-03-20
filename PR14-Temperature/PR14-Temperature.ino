// Project 4 – Temperature Sensor
// ADC and temperature value displays on Arduino Serial Monitor (open Arduino Serial Monitor).

int sensorPin = A0;
int sensorValue = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print("ADC: ");
  Serial.print(sensorValue);
  Serial.print(" Temperature: ");
  Serial.print(sensorValue * 0.488); // Convert ADC to celcius
  Serial.write(186);                 // ASCII degree symbol
  Serial.println("C");
  delay(100);
}

