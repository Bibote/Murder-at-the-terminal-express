#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    char path[300]; 

    getcwd(path,300); 

    strcat(path,"/history.txt"); 

    int fd = open(path,O_RDWR|O_APPEND|O_CREAT, 0644); 

    if(fd>0){ 
        char *command[50]; 
        //command = (char)malloc(sizeof(argv)*sizeof(char));

        for(int i=0; i<argc;i++){ //puts the arguments written on the terminal into an array (command)
            strcat(command,argv[i]); 
            strcat(command," "); 
        }  
        write(fd,command,strlen(command)); //writes the command on the history
        write(fd,"\n",sizeof("\n")); 
        close(fd); 
    }
}