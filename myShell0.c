   // myShell0
//////////////////////////////////////////////////
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
#include"commands/go.c"
#include <fcntl.h>
#include<signal.h>


#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20
#define MAX_PATH 200
#define ROUTE 

char route[80];
int read_args(int* argcp, char* args[], int max, int* eofp)
{
   static char cmd[MAXLINE];
   char* cmdp;
   int ret,i;

   *argcp = 0;
   *eofp = 0;
   i=0;
   while ((ret=read(0,cmd+i,1)) == 1) {
      if (cmd[i]=='\n') break;  // correct line
      i++;
      if (i>=MAXLINE) {
         ret=-2;        // line too long
         break;
      }
   }
   switch (ret)
   {
     case 1 : cmd[i+1]='\0';    // correct reading 
              break;
     case 0 : *eofp = 1;        // end of file
              return 0;
              break;
     case -1 : *argcp = -1;     // reading failure
              fprintf(stderr,"Reading failure \n");
              return 0;
              break;
     case -2 : *argcp = -1;     // line too long
              fprintf(stderr,"Line too long -- removed command\n");
              return 0;
              break;
   }
   // Analyzing the line
   cmdp= cmd;
   for (i=0; i<max; i++) {  /* to show every argument */
      if ((args[i]= strtok(cmdp, " \t\n")) == (char*)NULL) break;
      cmdp= NULL;
   }
   if (i >= max) {
      fprintf(stderr,"Too many arguments -- removed command\n");
      return 0;
   }
   *argcp= i;
   return 1;
}

//Function to register the commands
int registerCommand(char command[]) {
   //It ignores the history command
   if(!strcmp(command, " history\n")) {
      return 0;
   }
   //it opens the file of the history
   int fd;
    char fileroute[80];
    strcpy(fileroute, route);
    strcat(fileroute, "/history.txt");
    fd = open(fileroute,O_WRONLY | O_APPEND);
    //It checks if it opens the file correctly
    if (fd == -1) {
        printf("\033[0;31m");
        printf("There has been an error registering the command");
        printf("\033[0m");
        printf("\n");
        return 1;
    }

   //It writtes the command in the file.
   char store[50];
   strcpy(store,command);
    write(fd,store,strlen(store));


    

    //Closes everything.
    close(fd);
    return(1);
}

//Function that handles the alarm signal of the alarm to end the game
void sig_handler(int signum){
  printf("\033[0;36m");
  printf("\nTime is up, the train has reached its station, its time to decide who you think the assasin is:\n");
  char name[20];
  printf("\033[0m");

  //Gets the decision of the user
  scanf("%s", &name);

  //Checks if the name of the assasin is correct to end the game
  if(!strcmp(name, "Edurne") || !strcmp(name, "edurne") ) {
      printf("\033[0;32m");
      printf("Congratulations detective, you managed to catch the assasin\n");
      printf("\033[0m");
  }
  else {
   printf("\033[0;31m");
  printf("You were wrong, and left the assasin free\n");
  printf("\033[0m");
  }
  //Exits the father proccess closing the shell
  exit(0);
}

//This function will execute every command except the go
int execute(int argc, char *argv[])
{
   pid_t pid;
   int j;
   int i;
   char function[80];
   strcpy(function, "commands/");
   strcat(function, argv[0]);
   char ruta[80];
   strcpy(ruta, route);
   strcat(ruta, "/");
   
   strcat(ruta, function);
    //We fork to create the child proccess
    pid=fork();
    
    //The child proccess will do this
    if (pid==0) {

       char bufCom[50]="";
       //Registers the commands for the history
      for(j=0;j<argc;j=j+1) {
         strcat(bufCom, " ");
         strcat(bufCom, argv[j]);
      }
      strcat(bufCom,"\n");
      registerCommand(bufCom); 

      //Child proccess executes the program
         i=execv(ruta,argv);
       if(i=-1) {
            printf("That command doesn't exist");
         }
      int i=1;
      printf("\n");
      //Kills the child proccess
       exit(pid);
      
    }

    //The father proccess will do this
    else {
       //The father waits for the child
        wait(NULL);
     }
      
   
   
}


int main ()
{
   printf("Hi investigartor!! We are glad you are here... Unfortunately a murder has been commited in this train while it was on trip. We need you!! \n We hope that you can solve this unfortunate event. For doing that you are free to move around the train and interact with every onbject you fuond. \n Oh! O I was frogetting that you can interrogate every passenger in the train, we have prepared an special room for that near the restaurant, and we haven't tpuched anything on the crime scene. \n Everyone hopes you find the culprit of this... Good luck.");
   char * Prompt = "Lugage_room> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   char cwd[MAX_PATH];
   // clear history.txt file
   FILE *fp;
   fp = fopen("history.txt", "w");
   fclose(fp);
   //lock the crime scene  i will adapt it when the directory tree is final
   //chmod("crimescene",444);

   strcpy(route, getcwd(cwd,sizeof(cwd)));
   chdir("Luggage_room");
   signal(SIGALRM,sig_handler); // Register signal handler
 
  alarm(600);  // Scheduled alarm for 10 minutes 
   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         if (!strcmp(args[0],"go"))
         {
            if(go(argc,args)==1 && strcmp(args[1],"help")){
            
            char newPrompt[30]="";
            Prompt= strcat(newPrompt,args[1]);
            strcat(Prompt, ">> ");
            }
         }
   else{
         execute(argc, args);
         
   } 
      }
      if (eof) exit(0);
   }
}