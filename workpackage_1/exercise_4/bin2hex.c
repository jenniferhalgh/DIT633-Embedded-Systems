// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 1 
// Exercise 4, bin2hex 
// Submission code: 17F2A47
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    //variable declarations
    int binaryval[16];
    char numStr[16];
    int isBinary;

    //if no arguments were provided
    if (argc < 2)
    {
        //scan the value in stdout and save it in a char array
        scanf("%s", numStr);
    }
    //if arguments were provided
    else if (argc == 2)
    {
        //save the argument as a char array
        sscanf(argv[1], "%s", numStr);
    }

    //if numStr is equal to "-h" print information on how to use the program
    if (strcmp(numStr, "-h") == 0)
    {
        printf("%s", "This program will convert a binary number to a hexadecimal number.\nAn argument should be provided in the command line when executing the program, e.g. 'bin2hex.exe 00001111'.");
    }
    else
    {
        //For each character in the char array
        for (int i = 0; i < strlen(numStr); i++)
        {
            //If all the character are digits and the characters only contain 0's and 1's then the numStr is a valid binary number
            if (isdigit(numStr[i]) && (numStr[i] == '0' || numStr[i] == '1'))
            {
                isBinary = 1;
            }
            else
            {
                // If one of the characters is not a digit or numbers other than 0's and 1's are present, numStr is not a valid binary number
                isBinary = 0;
                //break out of the loop since its unecessary to check the other characters
                break;
            }
        }

        // If a valid binary number
        if (isBinary == 1)
        { 
            //for every char in numStr
            for (int i = 0; i < strlen(numStr); i++)
            {
                //Convert the char to an int and save it in the corresponding index in binaryval
                binaryval[i] = numStr[i] - '0';
            }

            //----Convert binary number to decimal number----
            //decimal number starts off as 0
            int decimal = 0;

            //for every value in binaryval
            for (int i = 0; i < strlen(numStr); i++)
            {
                //Calculate decimal by taking the sum of all values in binaryval multiplied with the value of 2^x, x being the value's index in the binary number
                decimal = decimal + (binaryval[i] * pow(2, strlen(numStr) - 1 - i));
            }

            char hexadecimal[16];
            int i;
            int remainder;
            const char hex[] = "0123456789ABCDEF"; //contains all possible values of the remainder
            //while decimal is bigger than 0
            for (i = 0; 0 < decimal; i++)
            {
                //divide decimal with 16 and save the remainder in remainder
                remainder = decimal % 16;
                //find the corresponding value of the remainder in hex and save that value in hexadecimal
                hexadecimal[i] = hex[remainder];
                //the remainding value of decimal will be decimal divided by 16
                decimal = decimal / 16;
            }

            //print the hexadecimal array in reverse to get the hexadecimal value in the right order
            for (i = i - 1; i >= 0; i--)
            {
                printf("%c", hexadecimal[i]);
            }
        }
        //If not a valid binary number print the error message and return 2
        else
        {
            printf("%s", "Error. The conversion was unsuccessful due to an invalid binary number.");
            return 2;
        }
    }
    return 0;
}
