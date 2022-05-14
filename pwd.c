#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[]) {

 //First we will search to see if the user is calling for help in the function, and show in the console how to use the function.
    if(argc==2){
        if(!strcmp(argv[1], "help")) {
        printf("\033[0;32m");
        printf("This command only needs one argument to be used: pwd. It shows the current directory.\n");
        printf("\033[0m");
        return 1;
        }
        else{
            printf("\033[0;31m");
            printf("Wrong ammount of parameters\n");
            printf("\033[0m");
            return 0;
        }
    }


    if(argc!=1){
    printf("\033[0;31m");
    printf("Wrong ammount of parameters\n");
    printf("\033[0m");
    return 0;
    }


   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       printf("\033[0;31m");
       perror("A error ocurred while getting the directory\n");
       printf("\033[0m");
       return 1;
   }
   return (0);
}