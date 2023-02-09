#define TEMPPIN A0 // Analog 0
#define PHOTORESPIN A1 // Analog 1
#define GREENLED 2 // Pin 2
#define REDLED 4 // Pin 4
#define BLUELED 7 //Pin 7
#define DELAY 500 //delay 500ms

int led;

void setup()
{
  Serial.begin(9600); //passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
  pinMode(GREENLED, OUTPUT); //send signal through GREENLED
  pinMode(REDLED, OUTPUT); //send signal through REDLED
  pinMode(BLUELED, OUTPUT); //send signal through BLUELED
}


void loop()
{
  //getting the voltage reading from the temperature sensor
 int temperature = calculate_temp(); //Calculate the temp and save the value
 int read_light = analogRead(PHOTORESPIN); //Read the analog value of the photoresistor
 int light_intensity = map(read_light,6,679,0,100); //convert the value to be in the range of 0-100

 
 Serial.print(temperature); Serial.println(" degrees C");
 Serial.print(light_intensity); Serial.println(" %");
  
  //If the led has a value
  if(led!=NULL){
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
      return REDLED;
      //if the temperature between -12-0
    } else if (temp>=-12 && temp<=0) {
      return GREENLED;
    } else {
      return BLUELED;
    }
    //if the light intensity is 21-60
  } else if (light>=21 && light<=60){
    //if the temperature is less than 0
    if(temp<0){
      return REDLED;
      //if the temperature between 0-20
    } else if (temp>=0 && temp<=20) {
      return GREENLED;
    } else {
      return BLUELED;
    }
    //if the light intensity is 61-100
  } else if (light>=61 && light<=100){
    //if the temperature is less than 21
    if(temp<21){
      return REDLED;
      //if the temperature is greater than or equal to 21
    } else if (temp>=21) {
      return GREENLED;
    }
  }
}

//method for calculating the temperature in celcius
int calculate_temp(){
  //Voltage at pin in milliVolts = (reading from ADC) * (5000/1024) 
  //Centigrade temperature = [(analog voltage in mV) - 500] / 10
  int vout = analogRead(TEMPPIN);//Read value from temppin
  float voltage = vout * 5; //multiply with 5 since we're using a 5V
  voltage/=1024; //divide with 1024 becaue the analog value is in the interval 0-1023
  voltage=voltage*1000; //turn the voltage to mV unit
  int tempInC = (voltage - 500) / 10; //Formula for calculating temperature: Temperature (°C) = (VOUT – 500) / 10 
  return tempInC;
  
}