#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{

    //First we will search to see if the user is calling for help in the function, and show in the console how to use the function.
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

    //If the user is not calling for the help function we will check that the function is called with the right ammount of parameters
    if(argc!=3){
        printf("Wrong ammount of parameters");
        return 0;
    }
    //We declare 2 variables one for the offset and another one for the file descriptor.
    int offset;
    int fd;

    //We use the open system call for the person we want to talk with in read mode.
    fd = open(argv[1],O_RDONLY);

    //If the file descriptor is -1 is because the name is not in the room with the person.
    if (fd == -1) {
        printf("There is no one with that name in the room with you");
        printf("\n");
        return 1;
    }

    //Now we will see the topic of the conversation and modify the offset to open the file in the topic of the conversation.
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

    //If the user didn't write an option of the available ones it will informe him.
    else {
        printf("He/She doesn`t want to talk about that");
        printf("\n");
        return 0;
    }

    //We will use the lseek function to open the file in the topic that the user wants to talk.
    lseek (fd, offset, SEEK_SET);
    
    //We will read the file character by character until a . is found.
    static char buff[500];
    int i=0;
    while (read(fd,buff+i,1) == 1) {
        
       if (buff[i]=='.') break;  // correct line
       i++;
    }
    printf("%s\n",buff);

    //Close everything and leave.
    close(fd);
    return(1);

}