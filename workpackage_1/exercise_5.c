// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 1 
// Exercise 5 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers
#define LOWER 1 // lowest value of random number 

 
// This function generates a set of random numbers and fills the table *tab with these numbers 
void create_random(int *tab ){

    srand(time(0)); // gives the rand() function a new seed to generate a new unique number each time the program is run

    int num[MAX]; // array with MAX indexes

    // for every number between 0 and 20
    for (int i = 0; i < MAX; i++) {
        // creates a random number for that index
        tab[i] = rand() % MAXNUMBER + LOWER;
    }
    
   
}

// This function takes the *tab of random numbers and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq ){
    int count;
    // for every random number value
    for(int i=0; i<MAXNUMBER; i++){
        count=0;
        // for every value between 0 and MAX 
        for(int j=0; j<MAX; j++){
            // if a value from table is equal to index value plus 1, then count increases by 1
            if(tab[j]==(i+1)){
                count++;
            }
        }
        // frequency of a certain number is equal to its count
        freq[i]=count;
    }
}

// This function takes the frequency count table and draws a histogram of the values in that frequency table

void draw_histogram(int *freq){
      int i, j;
      // for every values between 1 and 20
      for (i = 0; i < MAXNUMBER; i++) {
        // if there is no value of frequency, move to the next number
        if(!freq[i]){
            i++;
        }
        // print the random number values 
      printf("[%d] ", i+1);
      // for every value in frquency, print x
      for ( j = 0; j < freq[i]; ++j) {
      printf("x");
      }
      printf("\n");
   }
}

 
// The main entry point for the program 

int main (void){ 
 
    int table[MAX], n ; // array called table with MAX indexes
    int frequency[MAXNUMBER]; // array called frquency with MAXNUMBER indexes 

    create_random(table); // calling the create_random method with table as its input
    
    count_frequency(table, frequency); // calling the create_random method with table and frequency as its input

    // Printing histogram
    printf("\nHistogram: \n");

    draw_histogram(frequency); // calling draw_histogram with frequency as its input 
}

