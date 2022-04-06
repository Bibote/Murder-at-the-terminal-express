// myShell0
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "talk.c"
#include "functions.h"

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20

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



int execute(int argc, char *argv[])
{
   if (argv[0] == NULL) return 0;
   else if (!strcmp(argv[0],"go"))
   {
      return go(argc,argv);
   }
   else printf("wrong command");   
}
int execute2(int argc, char *argv[])
{
   int function=0 ;
   if(!strcmp(argv[0], "talk")) {
      function=1;
   }
   switch (function)
   {
     case 0 : printf("That comand doesnt exist\n");
              break;
     case 1 : if(argc==3) {
                  talk(argv[1],argv[2]);
               }
               else{
                  printf("%d arguments: ",argc);
                  printf("This command needs the name of the person you are talking with and what you want to talk about\n");
               }  
               break;         
              
     default : 
               break;
   }
}


int main ()
{
   char * Prompt = "myShell0> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   init();
   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         execute(argc, args);
      }
      if (eof) exit(0);
   }
}
