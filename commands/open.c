#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    
    if(argc==2)
    {
        if (strcmp(argv[1],"help")==0)
        {
            printf("\033[0;32m");
            printf("\n\n Enter the correct password in order to unlock Marcs_room\n");
            printf("Command syntax : open room_name password \n");
            printf("\nPress enter key to continue investigating");
            printf("\033[0m");
            getchar();
            system("clear");
            return 1;
        }
        else{
            printf("\033[0;31m");
            printf("\nWrong amount of parameters\n");
            printf("\033[0m");
        return 0;
        }
    }
    if(argc!=3){
        printf("\033[0;31m");
        printf("Wrong ammount of parameters\n");
        printf("\033[0m");
        return 0;
    }
    if (argc==3) //correct command
    {
        if (strcmp(argv[1],"Marc_room")==0)
        {
            if (strcmp(argv[2],"1234")==0)
            {
                chmod(argv[1],0777);
                printf("\nYou can access Marc's room \n");
                return 1;
            }
            else
    {   
        printf("\033[0;31m");
        printf("\nWrong password\n");
        printf("\033[0m");
        return 0;
    }
            
            
        }else
    {   
        printf("\033[0;31m");
        printf("\nWrong input\n");
        printf("\033[0m");
        return 0;
    }
        
    }
    else
    {   
        printf("\033[0;31m");
        printf("\nWrong input\n");
        printf("\033[0m");
        return 0;
    }

    
}
