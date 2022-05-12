#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


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
    int fd;
    char name[80];
    strcpy(name, argv[1]);

    struct stat sfile;
    stat(name, &sfile);
    printf("Last access = %o",sfile.st_atime);
    fd = open(name,O_RDONLY);
    if (fd == -1) {
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
    
    lseek (fd, offset, SEEK_SET);
    static char buff[10000];
    int i=0;
    while (read(fd,buff+i,1) == 1) {
        
       if (buff[i]=='.') break;  // correct line
       i++;
    }
    printf("%s\n",buff);

    
    close(fd);
    printf("\n");
    return(1);

}