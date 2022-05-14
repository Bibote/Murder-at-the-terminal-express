#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum){
 
  printf("Inside handler function\n");
  exit(0);
}
 
int main(){
 
  signal(SIGALRM,sig_handler); // Register signal handler
 
  alarm(2);  // Scheduled alarm after 2 seconds
int i;
  for(i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
}
return 0;
}