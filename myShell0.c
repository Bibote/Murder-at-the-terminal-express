// myShell0
//////////////////////////////////////////////////
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
#include"go.c"
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

int registerCommand(char command[]) {
   int fd;


    char fileroute[80];
    strcpy(fileroute, route);
    strcat(fileroute, "/history.txt");
    fd = open(fileroute,O_WRONLY | O_APPEND);
    if (fd == -1) {
        printf("There has been an error with the history");
        printf("\n");
        return 1;
    }


   char store[50];
   strcpy(store,command);
    write(fd,store,strlen(store));


    

    
    close(fd);
    printf("\n");
    return(1);
}
void sig_handler(int signum){
  printf("\033[0;36m");
  printf("\nTime is up, the train has reached its station, its time to decide who you think the assasin is:\n");
  char name[20];
  printf("\033[0m");
  scanf("%s", &name);
  if(!strcmp(name, "Edurne") || !strcmp(name, "edurne") ) {
      printf("\033[0;32m");
      printf("Congratulations detective, you managed to catch the assasin\n");
      printf("\033[0m");
  }
  else {
   printf("\033[0;31m");
  printf("You were wrong, and left the assain free\n");
  printf("\033[0m");
  }
  
  exit(0);
}

int execute(int argc, char *argv[])
{
   pid_t pid;
   int j;
   int i;
   char function[80];
   strcpy(function, argv[0]);
   char ruta[80];
   strcpy(ruta, route);
   strcat(ruta, "/");
   strcat(ruta, function);
    pid=fork();
    
    if (pid==0) {
       char bufCom[50]="";
       
      for(j=0;j<argc;j=j+1) {
         strcat(bufCom, " ");
         strcat(bufCom, argv[j]);
      }
      strcat(bufCom,"\n");
      registerCommand(bufCom); 
         i=execv(ruta,argv);
       if(i=-1) {
            printf("That command doesn't exist");
         }
      int i=1;
      printf("\n");
       exit(pid);
      
    }
    else {
        wait(NULL);
     }
      
   
   
}


int main ()
{
   char * Prompt = "your_room> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   char cwd[MAX_PATH];
   // clear history.txt file
   FILE *fp;
   fp = fopen("history.txt", "w");
   fclose(fp);
   
   
   strcpy(route, getcwd(cwd,sizeof(cwd)));
   chdir("your_room");
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