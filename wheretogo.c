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
    printf("\n_________ _____________ ___________ __________ _____________ ___________ ______________ ___________\n");
    printf("[luggage]-[lounge Room]-[staffroom]-[bathroom]-[crime scene]-[Cafeteria]-[smoking area]-[locomotive))\n");
    printf("°°°°°°°°° °°°°°°°°°°°°° °°°°°°°°°°° °°°°°°°°°° °°°°°°°°°°°°° °°°°°°°°°°° °°°°°°°°°°°°°° °°°°°°°°°°°\n");
    //get name of the current directory
    char s0[MAX_PATH];
    getcwd(s0,MAX_PATH);
    char *n = strrchr(s0, '/');
    printf("you are in: %s\n",n);
    // get grandparent directory
    printf("\nyou can go to:\n\n");
    char s1[MAX_PATH];
    getcwd(s1,MAX_PATH);
    char s2[MAX_PATH];
    getcwd(s2,MAX_PATH);
    char *p = strrchr(s2, '/');
    *p = '\0';
    p = strrchr(s2, '/');
    *p = '\1';
    printf("%s\n",p);
    // get same level directories
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
            if (ent->d_type == DT_DIR) {
            
            printf("%s\n", ent->d_name);}
        }
    }
    closedir(dir);

    

    



    
    return 0;
}
