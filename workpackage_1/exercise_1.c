#include <stdio.h>

int main()
{
    // Declare a variable called num of data type int
    int num;

    // do the following until it doesn't meet the while condition
    do
    {
        printf("Please input a number: ");

        // the input given in the console is the value of num
        scanf("%d", &num);

        // based on the value of num, one of the following cases will take place
        switch (num)
        {
        // This is what happens if the value of num is equal to 1
        case 1:
            printf("The number you have given is 1 \n");
            break;
        // This is what happens if the value of num is equal to 2
        case 2:
            printf("The number you have given is 2 \n");
            break;
        // This is what happens if the value of num is equal to 3
        case 3:
            printf("The number you have given is 3 \n");
            break;
        // This is what happens if the value of num is equal to 4
        case 4:
            printf("The number you have given is 4 \n");
            break;
        // This is what happens if the value of num is equal to 5
        case 5:
            printf("The number you have given is 5 \n");
            break;
        // If num is equal to any value that is not specified in the switch cases, the program will end
        default:
            break;
        }
        // The while condition states that the value of num must be between 1 and 5 in order for the program to run
    } while (num > 0 && num < 6);
}