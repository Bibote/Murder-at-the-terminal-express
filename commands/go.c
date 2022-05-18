#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_PATH 200

int go(int argc, char *argv[])
{
    system("clear");
    char s[200];
    printf("%s\n", getcwd(s, 200));

    if (argc != 2)
    {   printf("\033[0;31m");
        printf("Invalid number of arguments\n");
        printf("\033[0m");
        return 0;
    }
    if (!strcmp(argv[1], "help"))
    {   printf("\033[0;32m");
        printf("\n Use 'go' to move from one room to another. Remember this is a train you have to pass by each room in your path\n");
        printf("\n\n Go command syntax :  go 'Room'\n");
        printf("\n\nPress a key to continue investigation");
        printf("\033[0m");
        getchar();
        system("clear");
        return 1;
    }
    else if (chdir(argv[1]) == -1)
    {
        char s2[MAX_PATH];
            getcwd(s2,MAX_PATH);
            char *p = strrchr(s2, '/');
            *p = '\0';
            p = strrchr(s2, '/');
            char m[MAX_PATH];
            strcpy(m, s2);
            char n[MAX_PATH];
            strcpy(n, argv[1]);
            p=p+1;
         if (strcmp(argv[1], p)==0)
         {
            chdir(m);
            printf("%s\n", getcwd(s, 200));
            return 1;
         }
         else
         {
            printf("\033[0;31m");
            printf("You can't go to this room\n");
            printf("\033[0m");
            return 0;
         }
         
        
    }
    else if (chdir(argv[1]))
    {
        printf("%s\n", getcwd(s, 200));
        return 1;
    }
}
