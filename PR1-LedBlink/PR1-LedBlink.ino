// Project 1 - LED Blinking

int ledBlue = 11;
int ledRed = 10;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(ledBlue, HIGH);
  digitalWrite(ledRed, LOW);
  delay(100);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, HIGH);
  delay(100);
}
