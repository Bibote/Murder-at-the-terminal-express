#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <errno.h>
#include <dirent.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include <string.h>
#include "go.c"
 #define MAX_PATH 200


int main(int argc, char *argv[]){
    if(argc!=3 && argc !=4){
        printf("Enter a valid Command with Proper Arguments!\n");
        exit(EXIT_FAILURE);
    }
else{
    char myfile[100]="\0";
        strcat(myfile,argv[2]);
        strcat(myfile,"/");
        strcat(myfile,argv[1]);
        //printf("1 %s\n",myfile);
    int f1=open(argv[1],O_RDONLY);
    int f2= open(myfile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    long int n1;
    char buffer[4096];
    if(f1==-1){
        printf("the suspect is not in this room\n");
        close(f1);
        exit(1);
}
    if(argc==3){
        
        if(f2==-1){
            
            char s1[MAX_PATH];
            getcwd(s1,MAX_PATH);
            char *p = strrchr(s1, '/');
            *p = '\0';
            char s2[MAX_PATH];
            strcpy(s2,s1);
            p = strrchr(s2, '/');
            *p = '\1';
            
            if (strcmp(p,argv[2]))
            {
            strcat(s1,"/");
            strcat(s1,argv[1]);
            link(argv[1],s1);
            unlink(argv[1]);
            
            return 0;
            }
            close(f2);
            printf("you can not move the suspect to this room\n");
            exit(1);
        }
        
        link(argv[1],myfile);
        unlink(argv[1]); // Deleting the src file as contents have been moved
            printf("suspect is now in %s\n",argv[2]);
            close(f1);
            close(f2);
    }}
    return 0;


}