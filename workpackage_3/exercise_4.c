// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 3 
// Exercise 4
// Submission code: 1828E55

#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

char hexaKeys[ROWS][COLS] = { //defining the symbols on the buttons of the keypads
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pins out of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pins out of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  Serial.begin(9600); // passing 9600 in the speed parameter to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
}

void loop()
{
  char customKey = customKeypad.getKey(); // returns the key from keypad if it is pressed and stores as customKey
  
  if (customKey){ // if customKey exists
    Serial.println(customKey); // print the customKey in the serial monitor
  }
}