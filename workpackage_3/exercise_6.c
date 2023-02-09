#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 //Max number of characters in the string

void copyString(char *string)
{
    int size = 0;
    char copy[MAX + 1];

    //check length of string
    for (int i = 0; string[i] != '\0'; i++)
    {
        size++;
    }
    //if the size is bigger then 20
    if (size > MAX)
    {
        printf("Error, the string is too long. Max is 20 characters.");
    }
    else
    {   //
        copy[size] = '\0'; // set the last index to \0 to show termination of string
        //for each character in the string
        for (int i = 0; i < size; i++)
        {
            //put it in the corresponding index in copy
            copy[i] = string[i];
        }
        printf("Copied string: %s\nUsing copyString", copy);
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));          // set random seed
    char string[100];        //
    int nr = rand() % 2 + 1; // generate random number (1 or 2)
    char copy[MAX + 1];      // variable that will hold the copied string
    copy[MAX] = '\0';        // set the last index to \0 to show termination of string

    // If no argument provided (meaning the user input a filename in the command line)
    if (argc < 2)
    {
        // read the content
        scanf("%s", string);
    }
    else
    { // save the string in the string variable
        sscanf(argv[1], "%s", string);
    }
    // if the random number is 1
    if (nr == 1)
    {
        // if string is empty
        if (strlen(string) == 0)
        {
            printf("Error, the string is empty.");
            return 2;
        }

        // if number of characters exceed 20
        else if (strlen(string) > MAX)
        {
            printf("Error, the string is too long. Max is 20 characters.");
            return 2;
        }
        //use the strcpy function
        strcpy(copy, string);
        printf("Copied string: %s\nUsing strcpy", copy);
    }
    // if the random number is 2 use the copyString method
    else if (nr == 2)
    {
        copyString(string);
    }

    return 0;
}
