// Project 8 - Serial Interfacing

const int ledPin = 9;
unsigned char brightness;

void setup() 
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // check if data has been sent from the computer:
  if (Serial.available()> 0) 
  {
    // read the most recent value
    brightness = Serial.parseInt();
    //brightness = Serial.read();
    
    // set the brightness of the LED:
    analogWrite(ledPin, brightness);
    // echo the value
    Serial.print("The Brightness Value is ");
    Serial.println(brightness, DEC);
  }
}
