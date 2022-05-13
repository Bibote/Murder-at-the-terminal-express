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
    fd = open(fileroute,O_WRONLY);
    if (fd == -1) {
        printf("There has been an error with the history");
        printf("\n");
        return 1;
    }


    write(fd,"\n",1);
    write(fd,command,50);


    

    
    close(fd);
    printf("\n");
    return(1);
}


int execute(int argc, char *argv[])
{
   pid_t pid;
   int i;
   char function[80];
   strcpy(function, argv[0]);
   char ruta[80];
   strcpy(ruta, route);
   strcat(ruta, "/");
   strcat(ruta, function);
    pid=fork();
    if (pid==0) {
         i=execv(ruta,argv);
       if(i=-1) {
            printf("That command doesn't exist");
         }
      int i=1;
      char bufCom[50];
      strcpy(bufCom, argv[0]);
      for(i;i<argc;i++) {
         strcat(bufCom, " ");
         strcat(bufCom, argv[i]);
      }
      


       registerCommand(bufCom);    
       printf("\n");
       exit(pid);
    }
    else {
        wait(NULL);
     }
   
   
   
}


int main ()
{
   char * Prompt = "myShell0> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   char cwd[MAX_PATH];
   
   
   strcpy(route, getcwd(cwd,sizeof(cwd)));
   chdir("train_station");
   printf(getcwd(cwd,sizeof(cwd)));
      
   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         if (!strcmp(args[0],"go"))
         {
            if(go(argc,args)){
            //const char*newPrompt=args[1];
            char newPrompt[30]="";
            Prompt= strcat(newPrompt,args[1]);
            strcat(Prompt, ">> ");
         // store the last directory 
            }
         }
   else{
         execute(argc, args);
         
   } 
      }
      if (eof) exit(0);
   }
}