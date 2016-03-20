// Project 4 - RGB Mood LED

int ledBlue = 10;
int ledRed = 11;
int ledGre = 9;

int redVal;
int greenVal;
int blueVal;

void setup()
{
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
  // start out at black (all off)
  color_morph(&redVal,   1); // transition to red
  color_morph(&greenVal, 1); // transition to yellow
  color_morph(&redVal,   0); // transition to green
  color_morph(&blueVal,  1); // transition to aqua/cyan
  color_morph(&redVal,   1); // transition to white
  color_morph(&greenVal, 0); // transition to violet/magenta
  color_morph(&redVal,   0); // transition to blue
  color_morph(&blueVal,  0); // transition to black (all off)
}
