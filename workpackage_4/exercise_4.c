// Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 4 
// Exercise 4
// Submission code: 17E2E8A

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

//-----Function declarations-----
int search_number(int number, int tab[], int size); 
void sort (int number, int tab []);

//Main program
int main(int argc, char *argv[]){
    int test[] = {1,2,34,5,67,3,23,12,13,10}; //Initialize the array of integers
    int size = sizeof(test) / sizeof(test[0]); //calculate and store the size of the test array
    char numberStr[10];
    int number;
    int isNum;
    sscanf(argv[1], "%s",numberStr);
    //For each character in the char array
    for(int i=0; i<strlen(numberStr);i++){
    //If all the character are digits isNum=1
    if(isdigit(numberStr[i])){
        isNum = 1;
    //If one of the characters is not a digit or the input was empty isNum=0 
    } else if (!isdigit(numberStr[i])){
        isNum = 0;
        //and break out of the loop since its unecessary to check the other characters
        break;
    }
    
}
if(isNum==0){ //If not a number
    printf("Invalid input. Please enter numbers." );
    return 2;
} else { //if its a number

sscanf(numberStr, "%d",&number);
}
//call the search_number function and store its return value in result
 int result = search_number(number, test, size);
 //result is equal to -1 (i.e the integer couldn't be found)
 if(result==-1){
    printf("The number could not be found in the array.");
 } else {
    printf("The number can be found at index %d.", result);
 }
    //call the function to sort the array
    sort(size, test);
    return 0;

}

int search_number(int number, int tab[], int size){
    //for each element in the array
    for(int i=0; i<size; i++){
        //if the element is equal to the number we wanna find
        if(number==tab[i]){
            //return the index of that number
            return i;
    }
    }
    //if the number cannot be found return -1
    return -1;
}

void sort (int number, int tab []){
    int min=0;
    int temp;

    printf("\nSorted array: "); 

    //for each element in the array
    for(int j=0;j<number; j++){
        //set the index of the min value to be the first element of the array (of the unsorted part of the array)
        min=j;
        //for each element in the array
    for(int i=j;i<number; i++){
        //if the current element is smaller than the current min value
        if(tab[i]<tab[min]){
            //then set the min to be the current element's index
            min=i;
        }
    }

        //save the value of the first element in the unsorted part of the array in temp
        temp = tab[j];
        //set the first index in the unsorted part of the array to be equal to the min value
        tab[j]= tab[min];
        //set min value's old index to be equal to temp
        tab[min]= temp;

        //print the sorted array
      printf(" %d ", tab[j]);  
    }
    
}