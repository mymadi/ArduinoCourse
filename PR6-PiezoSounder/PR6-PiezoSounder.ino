// Project 6 - Piezo Sounder Alarm

int buz = 2;
float sinVal;
int toneVal;
unsigned char y = 180;
unsigned int z = 2000;
unsigned int w = 1000;

void setup() 
{
  pinMode(buz, OUTPUT);
}

void loop() 
{
  for (int x=0; x<y; x++) 
  {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/y)));
    // generate a frequency from the sin value
    toneVal = z+(int(sinVal*w));
    tone(buz, toneVal);
    delay(2);
  }
}
