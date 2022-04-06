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
   if (!strcmp(argv[0],"go"))
   {
      argc--;

      if (argc == 1)
      {
          
        char s[100];
        printf("%s\n",getcwd(s,100));
        chdir(argv[1]);
        printf("%s\n",getcwd(s,100));
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
   return 0;
}
void init(){
   char *args[20];
   args[0]= "go";
   args[1]= "launch_directory";
   go(2,args);
}

void describe_input(char *argv[],int argc)
{
   //talk(argv[1],argv[2]);
    switch (argc)
   {
     case 0 : printf("No argument\n");
              break;
     case 1 : printf("One argument: %s\n", argv[0]);
              
              break;
     default : printf("%s %d arguments: ", argv[0],argc-1);
               for (int i=1; i<argc; i++) printf("%s ", argv[i]);
               printf("\n");
               break;
   
}
}