#define ONELED 25 //the max temp for one LED
#define TWOLED 50 //the max temp for two LED 
#define THREELED 75 // the max temp for three LED
#define FOURLED 100 // the max temp for f
#define FIVELED 125 // 100-125 max

#define ZERO 0 // minimum temp for the LED to work

void setup() {
  pinMode(A2, INPUT); // signal received from analog pin A2 
  
  DDRD = B01111100; // set the port D3 to be output
  
  cli(); // stops interrupts 
  //setting up the interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // set entire TCCR1B register to 0 
  TCNT1  = 0; //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei(); // allows interrupts
}

void loop() { 
}

ISR(TIMER1_COMPA_vect){ // calling the interrupt and all the code inside it
  int sensor = analogRead(A2); //the value read from analog pin A2 stored in variable sensor 
  float voltage = (sensor / 1024.0) * 5.0; // coverting the value received from A2 into voltage 
  float tempC = (voltage - .5) * 100; // converting voltage into temperature celsius
  
  if (tempC < ZERO) { //if the LED is less than zero 
    PORTD = B00000000; // turn off all LEDs
  }
  else if (tempC >= ZERO && tempC <= ONELED) { //if the LED is greater than zero and less than or equal to 25 degree
    PORTD = B00000100; // turn on D2 LED
  }
  else if (tempC > ONELED && tempC <= TWOLED) { //if the LED is greater than 25 and less than  or equal to 50 degree
    PORTD = B00001100; // turn on D2, D3 LED
  }
  else if (tempC > TWOLED && tempC <= THREELED){ //if the LED is greater than 50 and less than  or equal to 75 degree
    PORTD = B00011100; // turn on D2, D3, D4 LED
  }
  else if (tempC > THREELED && tempC <= FOURLED){ //if the LED is greater than 75 and less than  or equal to 100 degree
    PORTD = B00111100; // turn on D2, D3, D4, D5 LED
  }
  else if (tempC > FOURLED && tempC <= FIVELED){ //if the LED is greater than 100 and less than  or equal to 125 degree
    PORTD = B01111100; // turn on D2, D3, D4, D5, D6 LED
  }
}