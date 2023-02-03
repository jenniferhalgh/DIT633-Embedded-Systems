#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 99

enum DIRECTION {N,O,S,W}; //Enum for directions (North, South, West and East)
 
//Struct ROBOT with attributes xpos, ypos and dir
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 

//Function for moving one step in a certain direction
void move(int *x, int *y, enum DIRECTION *direction){
    //If the direction is north, y is increased by 1
     if(*direction==N){
        *y+=1;
        //If the direction is east, x is increased by 1
     } else if (*direction==O){
        *x+=1;
        //If the direction is south, y is decreased by 1
     } else if (*direction==S){
        *y-=1;
        //If the direction is west, x is decreased by 1
     } else if (*direction==W){
        *x-=1;
     }
}

//Function to turn to a certain direction
void turn(enum DIRECTION *direction){
    //If previously facing north, turn 90 degrees to face east
    if(*direction==N){
        *direction=O;
        //If previously facing east, turn 90 degrees to face south
     } else if (*direction==O){
        *direction=S;
        //If previouly facing south, turn 90 degrees to face west
     } else if (*direction==S){
        *direction=W;
        //If previously facing west, turn 90 degrees to face north
     } else if (*direction==W){
        *direction=N;
     }
}


int main() {
    int playAgain = false;
    char answer[10];


    do{
    ROBOT position; //Declare position
    char walk[100]; //Declare walk
    bool correctLetters; //Declare correctLetters
    char numStr[100];
    printf("Please provide the starting position in x (0-99): ");
    //save x in position.xpos
    scanf("%d", &position.xpos);
    //Check that x is in the right interval (0-99)
    if(position.xpos>MAX || position.xpos<0){
        printf("The number must be in the interval 0-99.");
        return 2;
    } 
    printf("Please provide the starting position in y (0-99): ");
    //save y in position.ypos
    scanf("%d", &position.ypos);
    //Check that x is in the right interval (0-99)
    if(position.ypos>99 || position.ypos<0){
        printf("The number must be in the interval 0-99.");
        return 2;
    }

    printf("Please provide a string of characters with only m's and t's (m: move, t:turn): ");
    //Save the string in walk
    scanf("%s", walk);

    //for each character in the walk string
    for(int i=0; i<strlen(walk);i++){
    //if the char is not equal to m or t
    if(walk[i]=='m' || walk[i]=='t'){
        correctLetters = true;
    } else {
        correctLetters = false;
        break;
    }
    
}
//If correctLetters is false
if(!correctLetters){
    printf("Error. The string can only contain m's and t's.");

} else {
    //Start of with the robot facing north
    position.dir=N;

    //for each char in walk
    for(int i=0; i<strlen(walk);i++){
        //if the char is equal to m
        if(walk[i]=='m'){
            //call the move function
            move(&position.xpos, &position.ypos, &position.dir);
            //if the char is equal to t
        } else if(walk[i]=='t'){
            //call the turn function
            turn(&position.dir);
        }
    }
    printf("The new position is: \nx: %d, y: %d", position.xpos, position.ypos); 
    printf("\nPlay again? (y/n)" );
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

}   //Stay inside the while loop while playAgain is true
    } while (playAgain);
    
    return 1;
    
}

