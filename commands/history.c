#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX_PATH 200
int main(int argc, char* argv[])
{
    //First we will search to see if the user is calling for help in the function, and show in the console how to use the function.
    if(argc==2){
        if(!strcmp(argv[1], "help")) {
        printf("\033[0;32m");
        printf("This command only needs one argument to be used: lookHistory. It shows all the commands that the player has written on the terminal, even if they are not real commands.\n");
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

    if(argc!=1){
        printf("\033[0;31m");
        printf("Wrong ammount of parameters");
        printf("\n");
        printf("\033[0m");
        return 0;
    }
    
    char*p;
    char cwd[MAX_PATH];
    char route[80];
    getcwd(cwd,MAX_PATH);
    p = strrchr(cwd, '/');
    while (strcmp(p,"/Murder-at-the-terminal-express")!=0)
    {
        *p = '\0';
        p = strrchr(cwd, '/');
        //printf("cwd=%s\n",cwd);
        //printf("p=%s\n",p);
    }

    if (strcmp(p,"/Murder-at-the-terminal-express")==0)
    {
        strcpy(route,cwd);
        strcat(route, "/history.txt");
    } 
    
    
    

   //strcat(route, "/history.txt");

    int fd;

    struct stat sfile;
    stat(route, &sfile);
    fd = open(route,O_RDONLY);
    if (fd == -1) {
        printf("\033[0;31m");
        printf("There has been an error with the history");
        printf("\n");
        printf("\033[0m");
        return 0;
    }
    int i=sfile.st_size;
    static char buff[100];

    if(read(fd,buff,i)==-1) {
        printf("\033[0;31m");
        printf("error");
        printf("\033[0m");
        return 0;
    }
    else {
        printf("\033[0;35m");
        printf("%s",buff);
        printf("\033[0m");
    }

    

    
    close(fd);
    printf("\n");
    return(1);

}

//chdir("..");
    //strcpy(route, "/home/ahmed/Bureau/imane/Murder-at-the-terminal-express");