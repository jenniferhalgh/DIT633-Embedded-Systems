// declared variables 
int buttonState = 0;
#define BUTTONPIN 2
#define BLINKLED 13
#define BUTTONLED 12

void setup()
{
  pinMode(BUTTONPIN, INPUT); // receive signal through 2
  pinMode(BLINKLED, OUTPUT); // send signal through 13
  pinMode(BUTTONLED, OUTPUT); // send signal through 12
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(BUTTONLED, HIGH);
  delay(1000); // Wait for a second
  // turn the LED off by making the voltage LOW
  digitalWrite(BUTTONLED, LOW);
  delay(1000); // Wait for a second
  
  
  // read the state of the pushbutton
  buttonState = digitalRead(2);
  
  // check if the button is pressed. 
  if (buttonState == HIGH) {  // if the button is pressed 
    digitalWrite(BLINKLED, HIGH); // turn on the LED
  } else { // if the button is not pressed
    digitalWrite(BLINKLED, LOW); // turn off the LED 
  }
  delay(10); // Delay a little bit to improve simulation performance
}