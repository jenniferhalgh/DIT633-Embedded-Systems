// (C) Jennifer Hälgh & Sadhana Anandan, group: 25 (2023) 
// Work package 0 
// Exercise 1, 2 & 3
// Submission code: 35666666 
#include <stdio.h> 
#include <string.h>
  
    //Main functions with input arguments of type int and char
int main (int argc, char *argv[]) { 
    //If the arguments provided are less than 2 then print the following message
 if(argc<2){
        printf("%s","Error, you're missing an argument! Input '-h' to see more information.");    
    //If the arguments provided are equal to 2 and are not equal to "-h" print the following message
 } else if(argc==2 && strcmp(argv[1], "-h")!=0){
        printf("Hello World! - I'm %s!\n",argv[1]);    
    //If the arguments provided are greater than 2 then print the following message
 } else if (argc>2){ 
    printf("%s","Error. Too many arguments! Only provide 1 argument.");  
    //If the arguments provided are equal to 2 and are equal to "-h" print the following message
 } else if (argc==2 && strcmp(argv[1], "-h")==0){ 
    printf("%s","An argument should be provided in the command line, when executing the program, e.g. 'my_program.exe tom'");  
 }
    
 return 0;
} 