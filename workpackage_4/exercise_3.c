// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 4 
// Exercise 3
// Submission code: 17E2E8A

//include library for the LED strip
#include <Adafruit_NeoPixel.h>

// declaration of the 12-pixel LED ring on PIN 2
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12,2, NEO_GRB + NEO_KHZ800);

//variable for the analog temperature reading
int tempvalue;

//variable to know how far the thermometer reads
int lastled;

void setup(){
  ring.begin(); //start NeoPixel
 
  DDRD = B00001000; // set the port D3 to be output
  
  cli(); // stops interrupts 
  //setting up the interrupts
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
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

void loop(){
  
}

ISR(TIMER1_COMPA_vect){ // calling the interrupt and all the code inside it
tempvalue = analogRead(A5); //the value read from analog pin A5 
lastled = map(tempvalue, 12, 358, -1, 12); //calculates which should be the last led to light up and turns off the first LED at minimum temperature

  for (int i=0; i<12; i++){ // for every value from 0 to 12 (i)
    if(i<=lastled){ //if i is less than the value of lastled
       ring.setPixelColor(i,255,0,0); //the i'th led should turn on with red colour

      if(i==11){ // if i=11
        PORTD = B00001000; // turn on the LED (D3)
      } else {
        PORTD = B00000000; // turn off the LED
      }
      
    }else{
      ring.setPixelColor(i,0,0,0); // turn off the light
    }
  }
  ring.show(); // show everything
}