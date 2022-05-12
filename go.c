#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_PATH 200


bool go (int argc, char *argv[])
{
   system("clear");
   
   
      argc--;


      if (argc == 1)
      {
          
        char s[200];
        printf("%s\n",getcwd(s,200));
        if ( chdir(argv[1]) == -1 )
        {
           
            char s2[MAX_PATH];
            getcwd(s2,MAX_PATH);
            char *p = strrchr(s2, '/');
            *p = '\0';
            p = strrchr(s2, '/');
            *p = '\1';
         if (strcmp(argv[1], p))
         {
            strcat(s2,"/");
            strcat(s2,argv[1]);
            chdir(s2);
            return true;
         }
         

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
