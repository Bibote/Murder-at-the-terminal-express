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
#include"init.c"

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



int execute(int argc, char *argv[],int record, char *argv[])
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
      if (record==1){
         
      }else{
         i=execv(ruta,argv);
      }
      
      if(i=-1) {
         printf("That command doesn't exist");
      }
      printf("\n");
      exit(pid);
   }else {
      wait(NULL);
   }
}


int main ()
{
   char HISTPATH [456];
   char EXECPATH [456];
   char PREV_PATH[456]; 
   getcwd(HISTPATH,sizeof(HISTPATH));
   strcat(HISTPATH, "/History");
   getcwd(EXECPATH,sizeof(EXECPATH));
   strcat(EXECPATH, "/Executables");
   //We should make a short story introduction
   char * Prompt = "myShell0> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   char cwd[MAX_PATH];
   
   
   strcpy(route, getcwd(cwd,sizeof(cwd)));
   init();
   
   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         if (!strcmp(args[0],"go"))
         {
            if(go(argc,args)){
            //const char*newPrompt=args[1];
            char newPrompt[30]="";
            Prompt= strcat(newPrompt,args[1]);
            strcat(Prompt, "> ");
         // store the last directory 
            }
         }
   else{
         if((!strcomp(args[0],"history"))&&argc>1){
            getcwd(PREV_PATH,sizeof(PREV_PATH)); 
            chdir(HISTPATH); 
            char commandPath[456];
            execute()
         }
         execute(argc, args);
         
   } 
      }
      if (eof) exit(0);
   }
}

