#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_VALUE 10 //max number of allowed guesses

int main () {

    //playAgain starts off as false since it will be the very first game
    bool playAgain=false;

    //do-while since the first game is not dependent on the variable playAgain
    do{
        srand(time(0)); //gives the rand() function a new seed to generate a new unique number each time the program is run
    int count = 0; //amount of guesses
    int num = rand() % 100 + 1; //random number generator from 1-100
    char guessStr[10]; //the user's guess as a char array
    int guess=0; //the user's guess as an int
    int isNum; //0 if guessStr is a number, otherwise 1
    char answer[10]; //the user's answer to if they want to play again

//Game continues while the user has not guessed the right number & the amount of guesses does not exceed the MAX_VALUE
while(guess!=num && count<MAX_VALUE){

    printf("\n Guess the number between 1-100: " );

    //The user's input gets saved in guessStr
    scanf("%s", guessStr);

//For each character in the char array
for(int i=0; i<strlen(guessStr);i++){
    //If all the character are digits isNum=1
    if(isdigit(guessStr[i])){
        isNum = 1;
    //If one of the characters is not a digit or the input was empty isNum=0 
    } else if (!isdigit(guessStr[i]) || strlen(guessStr)==0){
        isNum = 0;
        //and break out of the loop since its unecessary to check the other characters
        break;
    }
    
}


if(isNum==0){ //If not a number
    fflush(stdin); //clear the input stream
    printf("\n Invalid input. Please enter numbers." );

} else { //if its a number

sscanf(guessStr, "%d",&guess); //convert the guess (which was saved as a string) to an int

//if the guess is out of the range of 1-100
if(guess>100 || guess<1){
        printf("\n Invalid input. You can only guess numbers in the range of 1-100." );
    } else {
        count++; //increase the amount of guesses by 1

        if(guess==num){//if the guess was correct
            printf("\n You have guessed %d times and your guess is correct", count);
        } else if (guess<num){ //if the guess was too low
            printf("\n Your guess is too low");
        if(count==MAX_VALUE){ //if the user has reached the max value of guesses
            printf("\n Out of guesses!" );
            }
    } else if (guess>num){ //if the guess was too high
            printf("\n Your guess is too high");
        if(count==MAX_VALUE){ //if the user has reached the max value of guesses
            printf("\n Out of guesses!" );
            }
    }
    }
}
}
printf("\n Would you like to play again? (y/n)" );
scanf("%s", answer); //Save the user's answer

//for each char in the answer
for(int i = 0; i<strlen(answer); i++){
  answer[i] = tolower(answer[i]); //turn the char into lowercase
}
//If the user answered yes
if(strcmp(answer, "y")==0 || strcmp(answer, "yes")==0){
playAgain = true;
} else {
    playAgain = false;
}
    } while (playAgain); //if playAgain is true, restart the game
 return 0;
} 
