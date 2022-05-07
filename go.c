#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>


bool go (int argc, char *argv[])
{
   system("clear");
   // changer current directory
   
   
      argc--;


      if (argc == 1)
      {
          
        char s[200];
        printf("%s\n",getcwd(s,200));
        if ( chdir(argv[1]) == -1 )
        {
           printf("there is no such place in the train\n");
           return false;
        }
        
        
        printf("%s\n",getcwd(s,200));
        return true;
        
      }
      else if (argc == 2)
      {
         if (chdir(argv[1]) == -1)
         {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return false;
         }
      }
      else
      {
         fprintf(stderr, "Error: Too many arguments\n");
         return false;
      }
}
