// Project 1 – PUSH BUTTON as DIGITAL INPUT
// When push button is pressed, LED on-board will turn ON. When push button is released, LED will turn OFF.

const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW) // Push button is pressed
    digitalWrite(ledPin, HIGH);
  else 
    digitalWrite(ledPin, LOW);
}  
