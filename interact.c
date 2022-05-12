#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    printf(argv[1]);
    if(argc!=2){
        printf("Wrong ammount of parameters");
        printf("\n");
        return 0;
    }
 
    if(!strcmp(argv[1], "help")) {
    printf("You just need to write the object you want to interact with");
    printf("\n");
    return 1;
    }
   

    int fd;


    struct stat sfile;
    stat(argv[1], &sfile);
    fd = open(argv[1],O_RDONLY);
    if (fd == -1) {
        printf("There is no object with that name in the room with you");
        printf("\n");
        return 1;
    }
    int i=sfile.st_size;
    static char buff[100];

    if(read(fd,buff,i)==-1) {
        printf("error");
    }
    else {
        printf(buff);
    }

    

    
    close(fd);
    printf("\n");
    return(1);

}