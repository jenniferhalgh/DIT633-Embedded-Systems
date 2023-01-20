#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        bool val_key = false;

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                val_key = true;
            }
            else
            {
                printf("Please give a valid positive integer for the key");
                return 1;
            }
        }

        if (val_key == true)
        {
            char message[100];
            do
            {
               printf("Enter a message to encrypt: ");
                fgets(message, sizeof(message), stdin);

                for (int i = 0; i < strlen(message); i++)
                {
                    if (isupper(message[i]))
                    {
                        message[i] = ((message[i] - 65 + key) % 26) + 65;
                    }
                    else if (islower(message[i]))
                    {
                        message[i] = ((message[i] - 97 + key) % 26) + 97;
                    }
                }
                printf("Encrypted message: %s", message); 
            } while (message[1]!=EOF);
        }
    }
    else
    {
        printf("Please only provide one key");
        return 1;
    }
}