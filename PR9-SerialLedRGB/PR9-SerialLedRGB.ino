// Project 9 - Serial Controlled RGB Mood LED

int ledBlue = 10;
int ledRed = 11;
int ledGre = 9;

int redVal;
int greenVal;
int blueVal;

unsigned char color;

void setup()
{
  Serial.begin(9600);
  Serial.println("Project 9 - Serial Controlled RGB Mood LED");
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGre, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  redVal = 255;
  greenVal = 255;
  blueVal = 255;
  update();
}

// This function updates the LED outputs.
void update()
{
  analogWrite(ledRed, redVal);
  analogWrite(ledGre, greenVal);
  analogWrite(ledBlue, blueVal);
}

void alloff()
{
  redVal = 255;
  greenVal = 255;
  blueVal = 255;
  
  analogWrite(ledRed, redVal);
  analogWrite(ledGre, greenVal);
  analogWrite(ledBlue, blueVal); 
}
// This function updates one of the color variables
// either getting brighter or getting dimmer.
// It also updates the outputs and delays for 10 milliseconds.
void color_morph(int* value, int get_brighter)
{
  for (int i = 0; i < 255; i++)
  {
    if (get_brighter)
      (*value)--;
    else
      (*value)++;
      
    update();
    delay(10);
  }
}

void loop()
{
  if (Serial.available()> 0) 
  {
    color = Serial.read();
    
    if (color == 'r')
    {
      alloff();
      color_morph(&redVal,   1); // red
      Serial.println("Red Color");
    }
    else if (color == 'b')
    {
      alloff();
      color_morph(&blueVal,   1); // blue
      Serial.println("Blue Color");
    }
    else if (color == 'v')
    {
      alloff();
      color_morph(&blueVal,   1); // violet
      color_morph(&redVal,   1);
      Serial.println("Violet/Magenta Color");
    }
    else
    {
      alloff();
      Serial.println("NO Color!");
    }
  }
//  // start out at black (all off)
//  color_morph(&redVal,   1); // transition to red
//  color_morph(&greenVal, 1); // transition to yellow
//  color_morph(&redVal,   0); // transition to green
//  color_morph(&blueVal,  1); // transition to aqua
//  color_morph(&redVal,   1); // transition to white
//  color_morph(&greenVal, 0); // transition to violet
//  color_morph(&redVal,   0); // transition to blue
//  color_morph(&blueVal,  0); // transition to black (all off)
}
