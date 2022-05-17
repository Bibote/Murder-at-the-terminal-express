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
 #define MAX_PATH 200
int main(int argc, char  *argv[])
{
    
    if(argc!=3)
    {
        if (strcmp(argv[1],"help")==0)
        {
            printf("\033[0;32m");
            printf("\n\nBefore interrogating a suspect you need to be alone in the room so you can't be interrupted by other people\n and to take the maximum information from each suspect, the interrogation room will be the staffroom ");
            printf("\n\n");
            printf("Remember that names start with Capital letters and that this is a train, so you need to pass by each room in your path ");
            printf("\n\n");
            printf("Command syntax :  isolate suspect Name Room\n");
            printf("\nPress enter key to continue investigating");
            printf("\033[0m");
            getchar();
            system("clear");
            return 1;
        }
        else
        {
            printf("\033[0;31m");
            printf("Wrong ammount of parameters");
            printf("\033[0m");
            return 0;
        }
    }
    else
    {
        DIR* dir = opendir(argv[2]);
        FILE *file;
        char s1[MAX_PATH];
            getcwd(s1,MAX_PATH);
            char *p = strrchr(s1, '/');
            *p = '\0';
            char s2[MAX_PATH];
            strcpy(s2,s1);
            p = strrchr(s2, '/');
            *p = '\1';
        if ((file = fopen(argv[1], "r")))
        {
            printf("file exist");
            fclose(file);
            if (dir) {
                    //printf("dossier existe");
                    closedir(dir);
                    strcat(argv[2],"/");
                    strcat(argv[2],argv[1]);
                    link(argv[1], argv[2]);
                    unlink(argv[1]);
                    printf("Suspect is now in %s\n",argv[2]);

                    return 0;
                }
            else if (strcmp(p,argv[2]))
            {
                strcat(s1,"/");
                strcat(s1,argv[1]);
                link(argv[1],s1);
                unlink(argv[1]);
                printf("Suspect is now in %s\n",argv[2]);

            
            return 0;
            }
            else {
                    printf("this room isn't  accessible from current room");
                    return 0;
                }

        }
        else
        {
            printf("file doesn't exist");
            return 0;
        }

            
                
    }

}

/*
int main(int argc, char *argv[]){
    if (argc == 2)
    {
        if (!strcmp(argv[1], "help"))
        {   printf("\033[0;32m");
            printf("\n\nBefore interrogating a suspect you need to be alone in the room so you can't be interrupted by other people\n and to take the maximum information from each suspect, the interrogation room will be the staffroom ");
            printf("\n\n");
            printf("Remember that names start with Capital letters and that this is a train, so you need to pass by each room in your path ");
            printf("\n\n");
            printf("Command syntax :  isolate suspect Name Room\n");
            printf("\nPress enter key to continue investigating");
            printf("\033[0m");
            getchar();
            system("clear");
            return 1;
        }
        else
        {   printf("\033[0;31m");
            printf("Wrong ammount of parameters");
            printf("\033[0m");
            return 0;
        }
    }
    if(argc!=3 && argc !=4){
        printf("\033[0;31m");
        printf("Enter a valid Command with Proper Arguments!\n");
        printf("\033[0m");
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
        printf("\033[0;31m");
        printf("The suspect is not in this room\n");
        printf("\033[0m");
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
            printf("\033[0;31m");
            printf("You can not move the suspect to this room\n");
            printf("\033[0m");
            exit(1);
        }
        
        link(argv[1],myfile);
        unlink(argv[1]); // Deleting the src file as contents have been moved
            printf("Suspect is now in %s\n",argv[2]);
            close(f1);
            close(f2);
    }}
    return 0;


}*/