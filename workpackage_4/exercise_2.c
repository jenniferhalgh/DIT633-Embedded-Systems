// C++ code
//

#include <Servo.h>
#define SERVOPIN A0 // Pin A0

int degrees = 0;   // the angle of the servo
Servo servo_A0;    // the servo itself
int count = 0;     // counter for how many times the ISR function runs
int clockwise = 0; // to keep track of the servo's spinning direction
int time = 0;      // total time in seconds

void setup()
{

    servo_A0.attach(SERVOPIN); // Attach the servo to pin A0
    servo_A0.write(0);         // Set the servo to a 0 degree angle

    // ----- COPIED FROM https://www.instructables.com/Arduino-Timer-Interrupts/ -----
    cli(); // stop interrupts
    // set timer2 interrupt at 8kHz
    TCCR2A = 0; // set entire TCCR2A register to 0
    TCCR2B = 0; // same for TCCR2B
    TCNT2 = 0;  // initialize counter value to 0
    // set compare match register for 8khz increments
    OCR2A = 249; // = (16*10^6) / (8000*8) - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM21);
    // Set CS21 bit for 8 prescaler
    TCCR2B |= (1 << CS21);
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);
    sei(); // allow interrupts
    // ----- COPIED FROM https://www.instructables.com/Arduino-Timer-Interrupts/ -----

    Serial.begin(9600); // passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
}

void loop() {}

ISR(TIMER2_COMPA_vect)
{
    count++; // increase count by one everytime this function runs

    // if the count has reached 8000, meaning 1 second has passed since the timer2 interrupts at every 1/8 millisecond (1/8 milliseconds * 8000 = 1 sec)
    if (count == 8000)
    {
        rotate(); // call the rotate function
    }
}

void rotate()
{
    if (degrees == 180) // if the servo has reached an angle of 180 degrees
    { 
        // set clockwise to 1 to indicate that the servo should start spinning clockwise
        clockwise = 1;
    }
    else if (degrees == 0)
    { // if the servo has reached an angle of 0 degrees
        // set clockwise to 0 to indicate that the servo should start spinning counter-clockwise
        clockwise = 0;
    }

    // if clockwise is equal to 0
    if (clockwise == 0)
    {
        degrees++; // increase degrees so it moves counter-clockwise
        
    }// if clockwise is equal to 1
    else if (clockwise == 1)
    {
        degrees--; // decrease degrees so it moves clockwise
    }

    time++;                  // increase time
    servo_A0.write(degrees); // turn the servo to the specified degree
    // print the total time in the serial
    Serial.print(time / 60);Serial.print(":");Serial.println(time % 60); 
    count = 0;                 // set count to 0 so the counter doesn't store too high numbers
}
