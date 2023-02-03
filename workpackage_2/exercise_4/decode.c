#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Check that the number of arguments are correct (1)
    if (argc > 2 || argc < 2)
    {
        printf("Error, number of arguments incorrect. Provide 1 argument.");
        return 1;
    }

    const char hex[] = "0123456789ABCDEF"; //Initializing array of the possible remainder chars for the hexadecimal
    char hexadecimal[2]; //Declaring the hexadecimal varible with 2 bits since 8 bits in binary corresponds to 2 bits in hexadecimal
    int validChar=0; //Initializing variable that will hold a true (1) or false (0) value
    unsigned char byte=0; //Initializing byte variable
    int values[5];//Declaring variable that will hold the 5 value

    //Save the argument in the hexadecimal variable
    sscanf(argv[1], "%s", hexadecimal);

    //For each character in hexadecimal
    for(int i = 0; i < strlen(hexadecimal); i++){
        //For each character in the hex array
        for(int j = 0; j < strlen(hex); j++){
            //if the character in hexadecimal does not exist in the hex array, then the hexadecimal number is invalid
        if(hexadecimal[i]==hex[j]){
            validChar=1;
            break;
        }
    }
    //If the hexadecimal number is invalid, print error message and exit program
    if(!validChar){
        printf("Error, invalid hexadecimal number.");
        return 1;
    }
    }

    //conver the hexadecimal to a long int in decimal form
    byte = strtol(hexadecimal, NULL, 16);

    //For each index in from 0-4 (5 values in the table)
    for(int i = 0; i < 5; i++){
        if(i==3 || i==4 || i==0){
            //right shift the byte with 7 to get the first number in byte
            values[i] = byte>>7;
            //if the value is out of range print error message and exit program
            if(values[i]>1){
                printf("Invalid hexadecimal number. The number results in a value out of range.");
                return 2;
            }
            //left shift byte by one to remove the number that has been assigned to values[i]
            byte = byte<<1;
        }
        if(i==2){
            //right shift the byte with 6 to get the first 2 numbers in byte
            values[i] = byte>>6;
            //if the value is out of range print error message and exit program
            if(values[i]>2){
                printf("Invalid hexadecimal number. The number results in a value out of range.");
                return 2;
            }
            //left shift byte by two to remove the numbers that has been assigned to values[i]
            byte = byte<<2;
        }
        if(i==1){
            //right shift the byte with 5 to get the first 3 numbers in byte
            values[i] = byte>>5;
            //if the value is out of range print error message and exit program
            if(values[i]>4){
                printf("Invalid hexadecimal number. The number results in a value out of range.");
                return 2;
            }
            //left shift byte by 3 to remove the number that has been assigned to values[i]
            byte = byte<<3;
        }
        
    }

    //Print the table with the values
    printf("Name         Value    \n----------------------------- \n");
    printf("engine_on        %d\n", values[0]);
    printf("gear_pos         %d\n", values[1]);
    printf("key_pos          %d\n", values[2]);
    printf("brake1           %d\n", values[3]);
    printf("brake2           %d", values[4]);

    return 0;
}