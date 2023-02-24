// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 5 
// Exercise 3 
// Submission code: 185F6BA

#include <DHT.h> // 0-50 degrees

#define DHTPIN A2     // data pin we're connected to
#define DHTTYPE DHT11   // or DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor

#define PHOTORESPIN A1 // Analog 1
#define GREENLED 2 // Pin 2
#define REDLED 4 // Pin 4
#define BLUELED 7 //Pin 7
#define DELAY 500 //delay 500ms

int led = 0;

void setup()
{
  Serial.begin(9600); //passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
  pinMode(GREENLED, OUTPUT); //send signal through GREENLED
  pinMode(REDLED, OUTPUT); //send signal through REDLED
  pinMode(BLUELED, OUTPUT); //send signal through BLUELED
  dht.begin(); 
  
}


void loop()
{
  //getting the voltage reading from the temperature sensor
 int temperature = dht.readTemperature();
 int read_light = analogRead(PHOTORESPIN); //Read the analog value of the photoresistor
 int light_intensity = map(read_light,6,679,0,100); //convert the value to be in the range of 0-100

 
 Serial.print(temperature); Serial.println(" degrees C");
 Serial.print(light_intensity); Serial.println(" %");
  
  //If the led has a value
  if(led!=0){
    //Turn the led light off
    digitalWrite(led, LOW);
  }
  //Call the led_light method to know which led to turn on
  led = led_light(light_intensity, temperature);
  //Turn on the led
  digitalWrite(led, HIGH);
  //delay 500ms
  delay(DELAY);
}

//method for determining which led to turn on
int led_light(int light, int temp){

    //if the light intensity is 0
  if(light==0){
    //if the temperature is -12 or higher
    if(temp>=-12){
      return REDLED;
    } else {
      return GREENLED;
    }
    //if the light intensity is 1-20
  } else if (light>=1 && light<=20){
    //if the temperature is less than -12
    if(temp<-12){
      return BLUELED;
      //if the temperature between -12-0
    } else if (temp>=-12 && temp<=0) {
      return GREENLED;
    } else {
      return REDLED;
    }
    //if the light intensity is 21-60
  } else if (light>=21 && light<=60){
    //if the temperature is less than 0
    if(temp<0){
      return BLUELED;
      //if the temperature between 0-20
    } else if (temp>=0 && temp<=20) {
      return GREENLED;
    } else {
      return REDLED;
    }
    //if the light intensity is 61-100
  } else if (light>=61 && light<=100){
    //if the temperature is less than 21
    if(temp<21){
      return BLUELED;
      //if the temperature is greater than or equal to 21
    } else if (temp>=21) {
      return GREENLED;
    }
  }
}