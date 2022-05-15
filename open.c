#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    printf("entrer");
    
    if (argc==3) //correct command
    {
        if (strcmp(argv[1],"Marc_room")==0)
        {
            if (strcmp(argv[2],"1234")==0)
            {
                chmod(argv[1],444);
                printf("\nYou can access the crime scene now \n");
            }
            
            
        }
        
    }
    else
    {
        printf("\nwrong input\n");
    }

    
}
