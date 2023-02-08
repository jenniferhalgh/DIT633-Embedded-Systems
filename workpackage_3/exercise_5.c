#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // declared variables
    int MAX = 10;
    int numbers[MAX];
    int i, intnum;

    srand(time(0)); // gives the rand() function a new seed to generate a new unique number each time the program is run
    for (i = 0; i < MAX; i++) // for every value from 0 to MAX
    {                                 
        numbers[i] = 1 + rand() % 99; // Generate a number between 1 to 99 and insert it in array index
    }

    printf("\nElements of the array:");

    for (i = 0; i < MAX; i++) // for every value from 0 to MAX
    {
        printf("\nIndex number %d:%d", i , numbers[i]); // print the value at each index
    }

    printf("\nElements of the array multiplied by 2:");
    for (i = 0; i < MAX; i++) // for every value from 0 to MAX
    {
        printf("\nIndex number %d:%d", i , (numbers[i] * 2)); // print the value at each index multiplied by 2
    }

    printf("\nThe value of the address of the array (pointer) is: %p", &numbers); // print the address of teh array
    printf("\nFirst integer in the array is (array[0]): %d", numbers[0]); // print the first integer of the array
    printf("\nThe last integer in the array is: %d", numbers[MAX - 1]); // print the last integer of the array
    printf("\nThe size of an integer (number of bytes) is: %zu bytes", sizeof(intnum)); // print the size of an integer
    printf("\nThe size of the whole array in bytes is: %zu bytes", sizeof(numbers)); // print the size of the whole array
    return 0;
}