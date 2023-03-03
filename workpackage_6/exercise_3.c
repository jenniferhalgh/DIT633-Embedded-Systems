// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 6 
// Exercise 3
// Submission code: 187A46A

#include <Adafruit_NeoPixel.h>
#include <Adafruit_Keypad.h>

const byte ROWS = 4; // keypad rows
const byte COLS = 4; // keypad columns

// define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {11, 10, 9, 8}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4};   // connect to the column pinouts of the keypad

Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, 2, NEO_GRB + NEO_KHZ800); //initialize the neopixel ring
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize the keypad

const String addresses[] = {"1365432", "A4D2143", "C21A32B", "9876543", "1234569", "B42A3C3", "DABCACB"}; //store the correct stargate addresses

String code = String(""); //initialize the varibale that will hold the user's code input

int count = 0; //initialize count to 0

bool wrongCode = false; //initialize wrongCode to be false

void setup()
{
    ring.begin(); // start NeoPixel
    customKeypad.begin(); //start keypad

    Serial.begin(9600); // passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
}

void loop()
{
    customKeypad.tick(); //

    while (customKeypad.available()) //while the keypad is available
    {
        keypadEvent e = customKeypad.read(); //read the keypad for input
        if (e.bit.EVENT == KEY_JUST_PRESSED) //if a key has been pressed
            code = String(code + (char)e.bit.KEY); //Save it in the code varible
        Serial.println(code);
    }

    delay(10);

    //if the user has input 7 digits/letters
    if (code.length() == 7)
    {
        
        for (int j = 0; j < code.length()+1; j++)
        {
            if (j == 4) //if its the 4th dial round
            {
                count++; //increase the count so the lights for the fourth digit gets increased by 2 indexes
            }
            //for each light on the neopixel
            for (int i = 0; i < 24; i++)
            {
                //if the light is not lit up with green
                if (ring.getPixelColor(i) != 65280)
                {
                    
                    ring.setPixelColor(i, 248, 200, 220); //set the color to pink
                }

                //if the current light is before index 5
                if (i < 5)
                {
                    //if the light (which is positioned 5 steps before the current light) is not lit up with green
                    if (ring.getPixelColor(19 + i) != 65280)
                    {
                        //turn off the light
                        ring.setPixelColor(19 + i, 0, 0, 0);
                    }
                }
                else //if the current light is at or after index 5
                {
                    //if the light (which is positioned 5 steps before the current light) is not lit up with green
                    if (ring.getPixelColor(i - 5) != 65280)
                    {
                        //turn off the light
                        ring.setPixelColor(i - 5, 0, 0, 0);
                    }
                }

                ring.show(); // show everything
                delay(100);
            }
            //if its after the first dial round
            if (j > 0)
            {
                //if count is 7 
                if (count == 7)
                {
                    //for each address in the address array
                    for (int i = 0; i < sizeof(addresses) / sizeof(addresses[0]); i++)
                    {
                        //if code is equal to one of the addresses
                        if (code == addresses[i])
                        {
                            //lock in the 7th digit on the neopixel to green
                            ring.setPixelColor(-3 + count * 3, 0, 255, 0);
                            ring.setPixelColor(-4 + count * 3, 0, 255, 0);
                            //show the color
                            ring.show();
                            //for each light on the neopixel
                            for (int i = 0; i < 24; i++)
                            {
                                //set the color to green
                                ring.setPixelColor(i, 0, 255, 0);
                                delay(50);
                                //show the color
                              	ring.show();
                              
                            }
                            wrongCode = false;
                            break; //break out of the loop (addresses array) since the correct address has already been found
                        }
                        //if the code is not correct
                        else
                        {
                            //set wrong code to true
                            wrongCode = true;
                        }
                    }
                }
                //if its before the 8th dial round (but after the 1st dial round)
                else
                {
                    //FOR THE FIRST LIGHT IN THE LIGHT PAIR
                    //if count * 3 + 20 is less than 23 (count * 3 determines where the green lights are positioned) 
                    // (less than 23 means that the light index has to be the ending lights)
                    if (20 + count * 3 <= 23)
                    {
                        //set color to green
                        ring.setPixelColor(20 + count * 3, 0, 255, 0);
                        ring.show(); // show everything
                    }
                    else
                    {   
                        //set color to green
                        ring.setPixelColor(-4 + count * 3, 0, 255, 0);
                        ring.show(); // show everything
                    }
                    //FOR THE SECOND LIGHT IN THE LIGHT PAIR
                    //if count * 3 + 21 is less than 23 (count * 3 determines where the green lights are positioned) 
                    // (less than 23 means that the light index has to be the ending lights)
                    if (21 + count * 3 <= 23)
                    {
                        //set color to green
                        ring.setPixelColor(21 + count * 3, 0, 255, 0);
                        ring.show(); // show everything
                    }
                    else
                    {
                        //set color to green
                        ring.setPixelColor(-3 + count * 3, 0, 255, 0);
                        ring.show(); // show everything
                    }

                    count++; //increase the count (which will help position the next pair of lights in the right indexes)
                }
            }
        }
        //if it was the wrong code
        if (wrongCode)
        {
            //for each light in the neopixel
            for (int i = 0; i < 24; i++)
            {
                //the the color to red
                ring.setPixelColor(i, 255, 0, 0);
                delay(50);
                //show the lights
                ring.show();
            }
        }
        count = 0; //reset the count to 0;
        code = ""; //reset code to emtpy string
        ////for each light in the neopixel
        for (int i = 0; i < 24; i++)
        {
            //turn the light off
            ring.setPixelColor(i, 0, 0, 0);
            delay(50);
            //show the light
            ring.show();
        }
    }
}