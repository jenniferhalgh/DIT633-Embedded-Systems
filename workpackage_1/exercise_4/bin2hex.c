#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int binaryval[16];
    char numStr[16];
    int isBinary;
    if (argc < 2)
    {
        scanf("%s", numStr);
    }
    else if (argc == 2)
    {
        sscanf(argv[1], "%s", numStr);
    }

    if (strcmp(numStr, "-h") == 0)
    {
        printf("%s", "This program will convert a binary number to a hexadecimal number.\nAn argument should be provided in the command line when executing the program, e.g. 'bin2hex.exe 00001111'.");
    }
    else
    {
        for (int i = 0; i < strlen(numStr); i++)
        {
            if (isdigit(numStr[i]) && (numStr[i] == '0' || numStr[i] == '1'))
            {
                isBinary = 1;

                // If one of the characters is not a digit or the input was empty isNum=0
            }
            else
            {
                isBinary = 0;
                // and break out of the loop since its unecessary to check the other characters
                break;
            }
        }

        if (isBinary == 1)
        { // If a valid number
            for (int i = 0; i < strlen(numStr); i++)
            {
                binaryval[i] = numStr[i] - '0';
            }
            int decimal = 0;

            for (int i = 0; i < strlen(numStr); i++)
            {

                decimal = decimal + (binaryval[i] * pow(2, strlen(numStr) - 1 - i));
            }

            char hexadecimal[16];
            int i;
            int remainder;
            const char hex[] = "0123456789ABCDEF";
            for (i = 0; 0 < decimal; i++)
            {
                remainder = decimal % 16;
                if (remainder < 10)
                {
                    hexadecimal[i] = hex[remainder];
                }
                else
                {
                    hexadecimal[i] = hex[remainder];
                }
                decimal = decimal / 16;
            }

            for (i = i - 1; i >= 0; i--)
            {

                printf("%c", hexadecimal[i]);
            }
        }
        else
        {
            printf("%s", "Error. The conversion was unsuccessful due to an invalid binary number.");
            return 2;
        }
    }
    return 0;
}
