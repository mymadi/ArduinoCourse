// Project 3 – Light Dependent Resistor
// When it is dark, the LED on-board will light up.

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
  if(sensorValue > 900)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}


