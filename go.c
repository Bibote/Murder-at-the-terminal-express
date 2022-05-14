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
    {
        printf("invalid number of arguments\n");
        return 0;
    }
    if (!strcmp(argv[1], "help"))
    {
        printf("\n use 'go' to move from one room to another. Remember this is a train you have to pass by each room in your path\n");
        printf("\n\n go command syntaxe :  go 'Room'\n");
        printf("\n\nPress a key to continue investigation");
        getchar();
        system("clear");
        return 1;
    }
    else if (chdir(argv[1]) == -1)
    {

        char s2[MAX_PATH];
            getcwd(s2,MAX_PATH);
            char *p = strrchr(s2, '/');
            //printf("s2=%s\n",s2);
            //printf("%s\n",p);
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
            printf("you can't go to this room\n");
            return 0;
         }
         
        
    }
    else if (chdir(argv[1]))
    {
        printf("%s\n", getcwd(s, 200));
        return 1;
    }
}
