#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

enum DIRECTION {N,O,S,W}; 
 
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 


void move(int *x, int *y, enum DIRECTION *direction){
     if(*direction==N){
        *y+=1;
     } else if (*direction==O){
        *x+=1;
     } else if (*direction==S){
        *y-=1;
     } else if (*direction==W){
        *x-=1;
     }
}

void turn(enum DIRECTION *direction){
    if(*direction==N){
        *direction=O;
     } else if (*direction==O){
        *direction=N;
     } else if (*direction==S){
        *direction=W;
     } else if (*direction==W){
        *direction=S;
     }
}

int main() {
    int playAgain = false;
    char answer[10];

    do{
    ROBOT position;
    char walk[100];
    bool correctLetters;
    printf("Please provide the starting position in x (0-99): ");
    scanf("%d", &position.xpos);
    if(position.xpos>99 || position.xpos<0){
        printf("The number must be in the interval 0-99.");
        return 2;
    }
    printf("Please provide the starting position in y (0-99): ");
    scanf("%d", &position.ypos);
    if(position.ypos>99 || position.ypos<0){
        printf("The number must be in the interval 0-99.");
        return 2;
    }

    printf("Please provide a string of characters (m & t): ");
    scanf("%s", walk);

    for(int i=0; i<strlen(walk);i++){
    if(walk[i]=='m' || walk[i]=='t'){
        correctLetters = true;
    } else {
        correctLetters = false;
        break;
    }
    
}

if(!correctLetters){
    printf("Error. The string can only contain m's and t's.");

} else {

    position.dir=N;

    for(int i=0; i<strlen(walk);i++){
        if(walk[i]=='m'){
            move(&position.xpos, &position.ypos, &position.dir);
        } else if(walk[i]=='t'){
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

}
    } while (playAgain);
    
    return 1;
    
}

