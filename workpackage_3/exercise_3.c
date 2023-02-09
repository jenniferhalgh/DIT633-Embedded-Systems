#define TEMPPIN A0 // Analog 0
#define DELAY 500 //delay 500ms

void setup()
{
  Serial.begin(9600);//passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
}

void loop()
{
  int vout = analogRead(TEMPPIN);//Read value from temppin
  float voltage = vout * 5; //multiply with 5 since we're using a 5V
  voltage/=1024; //divide with 1024 becaue the analog value is in the interval 0-1023
  voltage=voltage*1000; //turn the voltage to mV unit
  int tempInC = (voltage - 500) / 10; //Formula for calculating temperature: Temperature (°C) = (VOUT – 500) / 10 
  Serial.print(tempInC); Serial.println(" degrees C"); //Print to the serial
  delay(DELAY); // Wait for 500 milliseconds
}