#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    printf("Enter");
    
    if (argc==3) //correct command
    {
        if (strcmp(argv[1],"Marc_room")==0)
        {
            if (strcmp(argv[2],"1234")==0)
            {
                chmod(argv[1],0777);
                printf("\nYou can access Marc's room \n");
            }
            
            
        }
        
    }
    else
    {   
        printf("\033[0;31m");
        printf("\nWrong input\n");
        printf("\033[0m");
    }

    
}
