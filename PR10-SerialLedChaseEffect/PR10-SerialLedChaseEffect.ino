// Project 10 - Serial Controlled LED Chase Effect

byte ledPin[] = {4, 5, 6, 7, 8, 9};   // Create array for LED pins
int ledDelay(65);  // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
unsigned char chase;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Project 10 - Serial Controlled LED Chase Effect");
  for (int x=0; x<6; x++) 
  { // set all pins to output
    pinMode(ledPin[x], OUTPUT); 
  }
    changeTime = millis();
}

void loop() 
{
  if (Serial.available())
  {
    chase = Serial.read();
    
    if (chase == 'd')
    {
      Serial.println("Default Chase Effect");
      while(1)
      {
        if ((millis() - changeTime) > ledDelay) 
          { // if it has been ledDelay ms since last change
            changeLEDd();
            changeTime = millis();
            chase = Serial.read();
            if (chase == 's')
              {
                Serial.println("STOP!");
                clearLED();
                return;
              }
          }
      }
    }
    else if (chase == 'r')
    {
      Serial.println("Right to Left Chase Effect");
      while(1)
      {
        if ((millis() - changeTime) > ledDelay) 
          { // if it has been ledDelay ms since last change
            changeLEDrl();
            changeTime = millis();
            chase = Serial.read();
            if (chase == 's')
              {
                Serial.println("STOP!");
                clearLED();
                return;
              }
          }
      }
    }
    else
    {
      clearLED();
    }
  }
}

void changeLEDd() 
{
    for (int x=0; x<6; x++) 
    { // turn off all LED's
      digitalWrite(ledPin[x], LOW);
    }
     digitalWrite(ledPin[currentLED], HIGH);   // turn on the current LED
    currentLED += direction;                   // increment by the direction value
    // change direction if we reach the end
    if (currentLED == 5) {direction = -1;}
    if (currentLED == 0) {direction = 1;}
}

void changeLEDrl() 
{
    for (int x=0; x<6; x++) 
    { // turn off all LED's
      digitalWrite(ledPin[x], LOW);
    }
     digitalWrite(ledPin[currentLED], HIGH);   // turn on the current LED
    currentLED += direction;                   // increment by the direction value
    // change direction if we reach the end
    if (currentLED == 6) {currentLED = 0;}
}

void clearLED()
{
  for (int x=0; x<6; x++) 
  { // set all pins to output
    digitalWrite(ledPin[x], LOW); 
  }
}
