#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc==2){
        if(!strcmp(argv[1], "help")) {
        printf("To talk with someone you will need to write their name, and what do you want to talk a about(physical/moral/identity/accusation), you need to be in the same room of the person you want to talk with.");
        printf("\n");
        printf("Remember that names start with Capital letters!!");
        printf("\n");
        return 1;
        }
        else{
            printf("Wrong ammount of parameters");
            return 0;
        }
    }

    if(argc!=3){
        printf("Wrong ammount of parameters");
        return 0;
    }
    int offset;
    FILE *fp;
    char name[80];
    strcpy(name, argv[1]);
    strcat(name, ".txt");
    fp = fopen(name,"r");
    if (fp == NULL) {
        printf("There is no one with that name in the room with you");
        printf("\n");
        return 1;
    }
    if(!strcmp(argv[2], "physical")) {
        offset=0;
    }
    else if(!strcmp(argv[2], "moral")) {
        offset=36;
    }
    else if(!strcmp(argv[2], "identity")) {
        offset=52;
    }
    else if(!strcmp(argv[2], "accusation")) {
        offset=52;
    }
    else {
        printf("He/She doesn`t want to talk about that");
        printf("\n");
        return 0;
    }
    fseek( fp, offset, 1 );
    do {
        // Taking input single character at a time
        char c = fgetc(fp);
 
        // Checking for end of file
        if (feof(fp) || c=='.')
            break;
        printf("%c", c);

    } while(1);
    fclose(fp);
    printf("\n");
    return(1);

}