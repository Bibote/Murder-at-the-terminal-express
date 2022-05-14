#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_PATH 200
int main(int argc, char* argv[])
{
    if (argv[1]=="help"){
        printf(\033[0;32m);
        printf("This command only needs one argument to be used: lookHistory. It shows all the commands tha player has written on the terminal, even if they are not real commands.");
        printf(\033[0m);
    }
    if(argc!=2){
        printf(\033[0;3m);
        printf("Wrong ammount of parameters");
        printf("\n");
        printf(\033[0m);
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
    printf("sortie\n");

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
        printf(\033[0;3m);
        printf("There has been an error with the history");
        printf("\n");
        printf(\033[0m);
        return 1;
    }
    int i=sfile.st_size;
    static char buff[100];

    if(read(fd,buff,i)==-1) {
        printf(\033[0;3m);
        printf("error");
        printf(\033[0m);
    }
    else {
        printf("%s",buff);
    }

    

    
    close(fd);
    printf("\n");
    return(1);

}

//chdir("..");
    //strcpy(route, "/home/ahmed/Bureau/imane/Murder-at-the-terminal-express");