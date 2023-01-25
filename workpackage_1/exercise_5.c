#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab ){

    int lower = 1;

    srand(time(0));

    printf("The random numbers are: ");
    int num[MAX]; 
    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER + lower;
    }
    
   
}

// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );

void draw_histogram(int *freq){
      int i, j;
      for (i = 0; i < 100; i++) {
      printf("[%d] ", i);
      for ( j = 0; j < freq[i]; ++j) {
      printf("*");
      }
      printf("\n");
   }
}

// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
 
    int table[MAX], n ; 
    int frequency[MAXNUMBER]; 
    create_random(table);
    for( int i = 0; i<100; i++){
        printf("%d ", table[i]);
    }
}
