#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>



int main (int argc, char* argv[]) 
{ 
    if(argv[1]==NULL){ 
        char path[300]; 
        getcwd(path,300); 
        strcat(path,"/history.txt"); 
        int fd = open(path, O_RDONLY | O_CREAT, 0644);
	    chmod(path,0644); //to ensure the user's mask not applies

        if(fd<0){ 
            write(1,"You have done nothing yet!",sizeof("You have done nothing yet!"));
            close(fd); 
        }else{
            write(1,"These are the actions you have performed:\n\n",sizeof("These are the actions you have performed:\n\n"));
            char temp[4096]; 
            int lung; 

            while(lung=read(fd,temp,sizeof(temp))){//​read as much as 4096 in file 
                write(1,"\n",sizeof("\n"));
                write(1,temp,lung);//​write on terminal 
                write(1"\n",sizeof("\n")); 
            } 
            close(fd); 
        } 
    }else{
        write(1,"There are extra unwanted arguments.")
    }
}