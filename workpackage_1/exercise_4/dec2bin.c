#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int num;
    int num2;
    char numStr[16];
    int binary[16];
    int bit;
    int isNum;

sscanf(argv[1], "%s", numStr);
//For each character in the char array
if(strcmp(numStr, "-h")==0){
    printf("%s", "This program will convert a decimal number to a binary number.\nAn argument should be provided in the command line when executing the program, e.g. 'dec2bin.exe 12'.");
} else {
    for(int i=0; i<strlen(numStr);i++){
    //If all the character are digits isNum=1
    if(isdigit(numStr[i])){
        isNum = 1;
    //If one of the characters is not a digit or the input was empty isNum=0 
    } else if (!isdigit(numStr[i]) || strlen(numStr)==0){
        isNum = 0;
        //and break out of the loop since its unecessary to check the other characters
        break;
    }
    
}

if(isNum==1){ //If a valid number
   sscanf(argv[1], "%d", &num);
    num2 = num;
    int i;

    for (i = 0; 0 < num; i++)
    {

        binary[i] = num % 2;
        num = num / 2;
    }

    if (num2 <= 255 && num2>=0)
    {

        bit = 8;
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }
    } 
    else if (num2 > 255 && num2 <= 65535) {
        bit = 16;
        for (i = i; i < bit; i++)
        {
            binary[i] = 0;
        }

    }

    for (i = i - 1; i >= 0; i--)
    {

        printf("%d", binary[i]);
    }
} else {
    printf("%s", "Error. The conversion was unsuccessful due to an invalid integer.");
    return 2;
}
}

    return 0;
}