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
    
    // get grandparent directory
    char s1[MAX_PATH];
    getcwd(s1,MAX_PATH);
    
    DIR *dir;
    struct dirent *ent;
    dir = opendir(s1);
    if (dir == NULL) {
        printf("Could not open current directory\n");
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
