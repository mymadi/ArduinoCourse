// Project 3 - Pulsating LED

int ledBlue = 11;
int ledRed = 10;

float sinVal;
int ledVal;

void setup() 
{ 
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() 
{
  for (int x=0; x<180; x++) 
  {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledRed, ledVal);
    delay(25);
  }

  for (int y=0; y<180; y++) 
  {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(y*(3.1412/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledBlue, ledVal);
    delay(25);
  }
}

