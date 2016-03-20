// Project 2 – Potentiometer as an Analog Input
// When the potentiometer’s value changes, it will affect the on-board LED blinking speed.

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
