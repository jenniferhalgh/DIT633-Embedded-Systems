// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 1 
// Exercise 4, dec2bin 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_VALUE_LONG 4294967295 //Max value for type long
#define MAX_VALUE_32BIT 2147483647 //Max value of a 32 bit number
#define MAX_VALUE_16BIT 65535 //Max value of a 16 bit number
#define MAX_VALUE_8BIT 255 //Max value of a 8 bit number

int main(int argc, char *argv[])
{
    if(argc<2){
        printf("%s", "Error, no arguments were provided. Input '-h' for information on how to use the program.");
        return 2;
    }
    //variable declarations
    long num; 
    long num2;
    char numStr[16];
    int binary[32];
    int bit;
    int isNum;

//Put the argument in a char array 
sscanf(argv[1], "%s", numStr);

//if numStr is equal to "-h" print information on how to use the program
if(strcmp(numStr, "-h")==0){
    printf("%s", "This program will convert a decimal number to a binary number.\nAn argument should be provided in the command line when executing the program, e.g. 'dec2bin.exe 12'.");
} else {
    //For each character in the char array
    for(int i=0; i<strlen(numStr);i++){
    //If all the character are digits isNum=1
    if(isdigit(numStr[i])){
        isNum = 1;
    //If one of the characters is not a digit isNum=0 
    } else if (!isdigit(numStr[i])){
        isNum = 0;
        //break out of the loop since its unecessary to check the other characters
        break;
    }
    
}

if(isNum==1){ //If a valid number
    //Convert the number (saved as a string) to an integer
   sscanf(numStr, "%ld", &num);

   //if the number is bigger than the max value of type long
   if(num>MAX_VALUE_LONG){
    printf("%s", "Error. The number is too big.");
    return 2;
   }

   //Save the number in a new variable since the value of num will be manipulated
    num2 = num;

    int i; //index that will be used 

    //While num is bigger than 0
    for (i = 0; 0 < num; i++)
    {
        //Divide num with 2 and put the remainder in index i in the binary array
        binary[i] = num % 2;
        //Decrease num by half
        num = num / 2;
    }

    //if num (num2) is in the interval 0-255
    if (num2 <= MAX_VALUE_8BIT && num2>=0)
    {
        //treat num as an 8 bit integer
        bit = 8;

        //fill the remaining spots with 0's to fulfill 8 bits
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }
    } 
    //if num (num2) is in the interval 256-65535
    else if (num2 > MAX_VALUE_8BIT && num2 <= MAX_VALUE_16BIT) {
        //treat num as a 16 bit integer
        bit = 16;

        //fill the remaining spots with 0's to format 16 bits
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }

    } else if(num2 > MAX_VALUE_16BIT && num2 <= MAX_VALUE_32BIT){
        //treat num as a 32 bit integer
        bit = 32;

        //fill the remaining spots with 0's to format 32 bits
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }
    }

    ////print the binary array in reverse to get the binary value in the right order
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    //If not a valid integer print the error message and return 2
} else {
    printf("%s", "Error. The conversion was unsuccessful due to an invalid integer.");
    return 2;
}
}

    return 0;
}