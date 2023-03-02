// variables declared and initialized 
const int TRIG = 12; // arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO = 13; // arduino pin connected to Ultrasonic Sensor's ECHO pin
const int buzzer = 9; // pin connected to piezo 

#define MAXDIST 200
#define DISTONE 156
#define DISTTWO 112
#define DISTTHREE 68
#define DISTFOUR 25
#define DISTFIVE 3
#define MINDIST 112

float duration, dist;

void setup() {
  Serial.begin (9600); // initialize serial port
  pinMode(TRIG, OUTPUT); // set trig pin to output mode
  pinMode(ECHO, INPUT);  // set echo pin to input mode
  pinMode(buzzer, OUTPUT); // set piezo pin to output mode
  DDRD = B00111100; // // set the port D3, pins 2-5 to be output
}

void loop() {
  
  if(distance() < MAXDIST && distance() > DISTONE){
    LED(1);
  } else if(distance() < DISTONE && distance() > DISTTWO){
    LED(2);
  } else if(distance() < DISTTWO && distance() > DISTTHREE){
    LED(3);
  } else if(distance() < DISTTHREE && distance() > DISTFOUR){
    LED(4);
  } else if(distance() < DISTFOUR && distance() > DISTFIVE){
    LEDBLINK();
  } else if(distance() > MAXDIST){
    LED(5);
  }
  
  delay(500);
}

float distance(){
  digitalWrite(TRIG, LOW); // Give a short LOW pulse of 2 microseconds beforehand to ensure a clean HIGH pulse
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); // The sensor is triggered by a HIGH pulse of 10 microseconds.
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH); // measure duration of pulse from ECHO pin
  
  dist = (duration/2) / 29.1; // calculate the distance

  return dist;
}


void speaker(int n){
  tone(buzzer, 1000, n); // play noise with 1000 frequency and n duration
}

void LEDBLINK(){
    PORTD = B00111100;
    delay(100); // Wait for a 0.1 second
    PORTD = B00000000; // turn off all LEDs
    speaker(600); // play sound with 600 duration 
}

void LED(int n){
  if (n==1){
    PORTD = B00100000; // turn on one LED
    speaker(100); // play sound with 100 duration 
  } else if (n==2){
    PORTD = B00110000; // turn on two LED
    speaker(200); // play sound with 200 duration 
  } else if(n==3){
    PORTD = B00111000; // turn on three LED
    speaker(300); // play sound with 300 duration 
  } else if(n==4){
    PORTD = B00111100; // turn on four LED
    speaker(400); // play sound with 400 duration 
  } else if(n==5){
    PORTD = B00000000; // turn off all LEDs
  }
}