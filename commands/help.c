#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){


    if(argc!=1){
    printf("\033[0;31m");
    printf("Wrong ammount of parameters\n");
    printf("\033[0m");
    return 0;
    }

    printf("The goal of the game is to go around the train finding clues and talking to people to discover who the killer is\n\n");
    printf("Available commands:\n\n");
    printf("lookaround: To see if there is something to interact with \n");
    printf("wheretogo: if you are lost or search for new places\n");
    printf("talk: Allows to talk with  people\n");
    printf("go: Use it to move from a place to an other\n");
    printf("lookHistory: Prints a list of the used commands \n");
    printf("interact: Use to interacts with the different objects and people around the room\n");
    printf("isolate: Move a person to a room, in order to interrogate\n");
    printf("open: Used to open or lock rooms\n");
    printf("help: to see this message again\n\n");
    printf("You can also type a specific command followed by help, and it will show a brief explanation of how to use each command (Example: talk help)\n\n");
    printf("press enter to continue you investigation\n");
    getchar();
    system("clear");
    return (1);
    }
    
