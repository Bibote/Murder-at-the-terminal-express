#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_PATH 200

int main(int argc, char* argv[])
{

    //First we will search to see if the user is calling for help in the function, and show in the console how to use the function.
    if(argc==2){
        if(!strcmp(argv[1], "help")) {
        printf("\033[0;32m");
        printf("To talk with someone you will need to write their name, and what do you want to talk a about(physical/moral/identity/accusation),\nyou need to be in the same room of the person you want to talk with.");
        printf("\n");
        printf("Remember that names start with Capital letters!!");
        printf("\n");
        printf("\033[0m");
        return 1;
        }
        else{
            printf("\033[0;31m");
            printf("Wrong ammount of parameters\n");
            printf("\033[0m");
            return 0;
        }
    }

    //If the user is not calling for the help function we will check that the function is called with the right ammount of parameters
    if(argc!=3){
        printf("\033[0;31m");
        printf("Wrong ammount of parameters\n");
        printf("\033[0m");
        return 0;
    }

    //We get the name of the room
    char cwd[MAX_PATH];
    char folder[10];
    getcwd(cwd, sizeof(cwd));
    int i=0;
    int j=0;
    for(i;i<strlen(cwd);i++) {
        if(cwd[i]=='/') {
            j=i;
        }
    }
    //We check if we are in the right room
    memcpy(folder,&cwd[j+1],strlen(cwd)-j);
    if(strcmp(folder, "interrogation_room")) {
        printf("\033[0;31m");
        printf("People will only talk with you in the interrogation_room\n");
        printf("\033[0m");
        return 0;
    }
    //We declare 2 variables one for the offset and another one for the file descriptor.
    int offset;
    int fd;
    char name[20];
    strcpy(name,argv[1]);

    //We check if the person the user wants to talk to is in the train.
    int real =0;
    if(strcmp(name, "Millan")  ) {
        real=1;
    }
    else if(strcmp(name, "Edurne")  ) {
        real=1;
    }
    else if(strcmp(name, "Edurne")  ) {
        real=1;
    }
    else if(strcmp(name, "Edurne")  ) {
        real=1;
    }
    else if(strcmp(name, "Edurne")  ) {
        real=1;
    }
    if(real==0) {
        printf("\033[0;31m");
        printf("There is no one with that name in the train\n");
        printf("\033[0m");
        return 0;
    }
    
    //We use the open system call for the person we want to talk with in read mode.
    fd = open(name,O_RDONLY);

    //If the file descriptor is -1 is because the name is not in the room with the person.
    if (fd == -1) {
        printf("\033[0;31m");
        printf("There is no one with that name in the room with you");
        printf("\033[0m");
        printf("\n");
        return 1;
    }

    //Now we will see the topic of the conversation and modify the offset to open the file in the topic of the conversation.
    if(!strcmp(argv[2], "physical")) {
        offset=0;
    }
    else if(!strcmp(argv[2], "moral")) {
        offset=96;
    }
    else if(!strcmp(argv[2], "identity")) {
        offset=388;
    }
    else if(!strcmp(argv[2], "relationship")) {
        offset=565;
    }
    else if(!strcmp(argv[2], "accusation")) {
        offset=698;
    }

    //If the user didn't write an option of the available ones it will informe him.
    else {
        printf("\033[0;31m");
        printf("He/She doesn`t want to talk about that");
        printf("\033[0m");
        printf("\n");
        return 0;
    }

    //We will use the lseek function to open the file in the topic that the user wants to talk.
    lseek (fd, offset, SEEK_SET);
    
    //We will read the file character by character until a . is found.
    static char buff[500];
    i=0;
    while (read(fd,buff+i,1) == 1) {
        
       if (buff[i]=='.') break;  // correct line
       i++;
    }
    printf("\033[0;36m");
    printf("%s\n",buff);
    printf("\033[0m");
    //Close everything and leave.
    close(fd);
    return(1);

}