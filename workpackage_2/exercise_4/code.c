// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 2 
// Exercise 4-code
// Submission code: 180DC4E
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    //Check that the number of arguments are correct (5)
    if (argc > 6 || argc < 6)
    {
        printf("Error, number of arguments incorrect. Provide 5 arguments.");
        return 1;
    }

    unsigned char byte; //declaring variable byte where the bits will be packed into
    char numStr[5]; //declaring variable that will hold the 5 arguments as a string
    int isNum;//declaring variable which will hold a true (1) or false (0) value

    // For each argument
    for (int i = 0; i < argc - 1; i++)
    {
        // save it as a character in the numStr array
        sscanf(argv[i + 1], "%s", &numStr[i]);
    }

    // For each char in the numStr array
    for (int i = 0; i < 5; i++)
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

    //if all arguments are not digits
    if(isNum==0){
        printf("Error, the values should be numbers.");
        return 2;
    }

    //checks if all of the arguments are in range
    if(strtol(argv[1], NULL, 10)>1 || strtol(argv[1], NULL, 10)<0 || strtol(argv[4], NULL, 10)>1 || strtol(argv[4], NULL, 10)<0 || strtol(argv[5], NULL, 10)>1 || strtol(argv[5], NULL, 10)<0){
        printf("Out of range. The range for argument 1, 4 and 5 is 0-1\n");
        return 2;
    } else if (strtol(argv[2], NULL, 10)>4 || strtol(argv[2], NULL, 10)<0) {
        printf("Out of range for argument 2. The range is 0-4\n");
        return 2;
    } else if (strtol(argv[3], NULL, 10)>2 || strtol(argv[3], NULL, 10)<0) {
        printf("Out of range for argument 3. The range is 0-2\n");
        return 2;
    } 

   //At first byte is equal to the last value (brake2) (so it's in bit no 7)
    byte=strtol(argv[5], NULL, 10); 
    //left-shifting the fourth value's bit one step (so it's in bit no 6)
    //combine the bit value of byte with the bit value of the argument  (brake1)
    byte = byte | (strtol(argv[4], NULL, 10)<<1);

    //left-shifting the third value's bit two steps (so it takes up 2 bits from bit no 3-5)
    //combine the bit value of byte with the bit value of the argument  (key_pos)
    byte = byte | (strtol(argv[3], NULL, 10)<<2);

    //left-shifting the second value's bit four steps (so it takes up 3 bits from bit no 1-3)
    //combine the bit value of byte with the bit value of the argument  (gear_pos)
    byte = byte | (strtol(argv[2], NULL, 10)<<4);

    //left-shifting the first value's bit seven steps (since its supposed to be in bit no 0)
    // and combine the bit value of byte with the bit value of the argument (engine_on)
    byte = byte | (strtol(argv[1], NULL, 10)<<7);

    //print out the byte in hexadecimal form
    printf("%X", byte);

    return 0;
}