#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // If the number of arguments given in the command line is equal to 2
    if (argc == 2)
    {
        int key = atoi(argv[1]); // convert string argument given in console into an integer called 'key'
        bool val_key = false; // store the validity of the key in the form of boolean datatype

        // for every digit in the argument
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // if the digit is a valid number, then the validity of the key becomes true
            if (isdigit(argv[1][i]))
            {
                val_key = true;
            }
            else
            // else give a valid number
            {
                printf("Please give a valid positive integer for the key");
                return 1;
            }
        }

        // if the validity of the key is true
        if (val_key == true)
        {
            char message[100]; // declare a character array called message with 100 index

            // do the following until it doesn't meet the while condition
            do
            {
                printf("Enter a message to encrypt: ");

                // reads the message given in the console and stores it in the message array. The maximum number of characters 
                // to be read and stored in the array will be the same as the size of the message array.
                // The input stream will be the standard input. 
                fgets(message, sizeof(message), stdin);

                // for every charcater in the message array
                for (int i = 0; i < strlen(message); i++)
                {
                    // if the character is uppercase, it must go through the equation and
                    // its value will be updated
                    if (isupper(message[i]))
                    {
                        message[i] = ((message[i] - 65 + key) % 26) + 65;
                    }
                    // if the character is lowercase, it must go through the equation and
                    // its value will be updated
                    else if (islower(message[i]))
                    {
                        message[i] = ((message[i] - 97 + key) % 26) + 97;
                    }
                }
                printf("Encrypted message: %s", message); // print the updated message array
            } while (message[1] != EOF); // The while condition states that if argument given is EOF, the program will stop running
        }
    }
    else if (argc == 1) // if no argument is provided 
    {
        printf("Please provide a key");
        return 1;
    }
    else // if an argument is neither provided nor it is one value, then
    {
        printf("Please provide only one key");
        return 1;
    }
}