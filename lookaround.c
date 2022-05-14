#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
#include <dirent.h>
#define MAX_PATH 200

int main(int argc, char const *argv[])
{
    if(argv[1]=="help"){
        printf(\033[0;32m);
        printf("This command only needs one argument to be used: lookaround. It shows all the objects and peopel on the room you are in.");
        printf(\033[0m);
    }
    // get grandparent directory
    char s1[MAX_PATH];
    getcwd(s1,MAX_PATH);
    
    DIR *dir;
    struct dirent *ent;
    dir = opendir(s1);
    if (dir == NULL) {
        printf(\033[0;3m);
        printf("Could not open current directory\n");
        printf(\033[0m);
        return -1;
    }
    while ((ent = readdir(dir)) != NULL) {
        
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            // verify if it is a directory
            if (ent->d_type != DT_DIR) {
            
            printf("%s\n", ent->d_name);}
        }
    }
    closedir(dir);
    return 0;
}
