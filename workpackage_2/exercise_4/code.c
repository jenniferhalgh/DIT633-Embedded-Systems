#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main(int argc, char *argv[])
{
    //Check that the number of arguments are correct (5)
    if (argc > 6 || argc < 6)
    {
        printf("Error, number of arguments incorrect. Provide 5 arguments.");
        return 1;
    }

    unsigned char byte; //declaring variable byte where the bits will be packed into
    int values[5]; //declaring values variable with 5 bits since there will only be 5 values
    char numStr[5]; //declaring variable that will hold the 5 arguments as chars before they are converted to ints
    int isNum;//declaring variable which will hold a true (1) or false (0) value

    // For each argument
    for (int i = 0; i < argc - 1; i++)
    {
        // save it as a character in the numStr array
        sscanf(argv[i + 1], "%s", &numStr[i]);
    }

    // For each char in the numStr array
    for (int i = 0; i < strlen(numStr); i++)
    {
        // If all the characters are digits isNum=1
        if (isdigit(numStr[i]))
        {
            isNum = 1;

        } // If one of the characters is not a digit isNum=0
        else if (!isdigit(numStr[i]))
        {
            isNum = 0;
            // and break out of the loop since its unecessary to check the other characters
            break;
        }
    }


    for (int i = 0; i < strlen(numStr); i++)
    {
        // Convert all the characters in numStr to an int and save it in the corresponding index in the values array
        values[i] = numStr[i] - '0';
    }

    //At first byte is equal to the last value (brake2) (so it's in bit no 7)
    byte=values[4]; 

    //left-shifting the fourth value's bit one step (so it's in bit no 6)
    values[3]=values[3]<<1;
    //combine the bit value of byte with the bit value of value[3] (brake1)
    byte = byte | values[3];

    //left-shifting the third value's bit two steps (so it takes up 2 bits from bit no 3-5)
    values[2]=values[2]<<2;
    //combine the bit value of byte with the bit value of value[2] (key_pos)
    byte = byte | values[2];

    //left-shifting the second value's bit four steps (so it takes up 3 bits from bit no 1-3)
    values[1]=values[1]<<4;
    //combine the bit value of byte with the bit value of value[1] (gear_pos)
    byte = byte | values[1];

    //left-shifting the first value's bit seven steps (since its supposed to be in bit no 0)
    values[0]=values[0]<<7;
    //combine the bit value of byte with the bit value of value[0] (engine_on)
    byte = byte | values[0];

    //print out the byte in hexadecimal form
    printf("%X", byte);

    return 0;
}