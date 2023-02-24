// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 5 
// Exercise 2 
// Submission code: 185F6BA

#include <DHT.h> // DHT library

#define TEMP1 25.00 //the min temp for one LED
#define TEMP2 25.20 //the min temp for two LED 
#define TEMP3 25.40 // the min temp for three LED
#define TEMP4 25.60 // the min temp for four LED
#define TEMP5 25.80 // the min temp for five LED
#define TEMP6 26.00 // the max temp for all five LEDS

#define DHTPIN A2     // data pin we're connected to
#define DHTTYPE DHT11   // or DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor

//Variable to store temperature value
float temp;

void setup() {

  Serial.begin(9600);
  dht.begin();
  
  DDRD = B01111100; // set the port 2-6 to be output
 
}

void loop() { 
  temp = dht.readTemperature(); // stores the value of temp read from sensor 

  delay(2000); 
 
   if (temp < TEMP1) { //if the LED is less than zero 
    PORTD = B00000000; // turn off all LEDs
    Serial.print("Temp: ");
    Serial.print(temp);
  }
  else if (temp >= TEMP1 && temp <= TEMP2) { //if the LED is greater than zero and less than or equal to 25 degree
    PORTD = B00000100; // turn on D2 LED
    Serial.print("Temp: ");
    Serial.print(temp);
  }
  else if (temp > TEMP2 && temp <= TEMP3) { //if the LED is greater than 25 and less than  or equal to 50 degree
    PORTD = B00001100; // turn on D2, D3 LED
    Serial.print(" Temp: ");
    Serial.print(temp);
  }
  else if (temp > TEMP3 && temp <= TEMP4){ //if the LED is greater than 50 and less than  or equal to 75 degree
    PORTD = B00011100; // turn on D2, D3, D4 LED
    Serial.print("Temp: ");
    Serial.print(temp);
  }
  else if (temp > TEMP4 && temp <= TEMP5){ //if the LED is greater than 75 and less than  or equal to 100 degree
    PORTD = B00111100; // turn on D2, D3, D4, D5 LED
    Serial.print("Temp: ");
    Serial.print(temp);
  }
  else if (temp > TEMP5 && temp <= TEMP6){ //if the LED is greater than 100 and less than  or equal to 125 degree
    PORTD = B01111100; // turn on D2, D3, D4, D5, D6 LED
    Serial.print("Temp: ");
    Serial.print(temp);
  }
}
