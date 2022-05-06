#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
   //system("clear");
   // changer current directory
   if (!strcmp(argv[0],"go"))
   {
      argc--;

      if (argc == 1)
      {
          
        char s[100];
        printf("%s\n",getcwd(s,100));
        chdir(argv[1]);
        printf("%s\n",getcwd(s,100));
        return 1;
        
      }
      else if (argc == 2)
      {
         if (chdir(argv[1]) == -1)
         {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return -1;
         }
      }
      else
      {
         fprintf(stderr, "Error: Too many arguments\n");
         return -1;
      }
   }
   return 0;
}