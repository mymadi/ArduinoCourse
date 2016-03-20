// Project 2 - LED Fading

unsigned char i,j;
int ledBlue = 10;
int ledRed = 11;

void setup() 
{
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() 
{  
  for (i = 0; i <255 ; i++)
  {
    analogWrite(ledBlue, i);
    delay(25);
  }

  for (j = 0; j <255 ; j++)
  {
    analogWrite(ledRed, j);
    delay(25);
  }
}
