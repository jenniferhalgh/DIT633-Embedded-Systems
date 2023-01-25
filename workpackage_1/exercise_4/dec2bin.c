#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
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
   if(num>4294967295){
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
    if (num2 <= 255 && num2>=0)
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
    else if (num2 > 255 && num2 <= 65535) {
        //treat num as a 16 bit integer
        bit = 16;

        //fill the remaining spots with 0's to format 16 bits
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }

    } else if(num2 > 65535 && num2 <= 2147483647){
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