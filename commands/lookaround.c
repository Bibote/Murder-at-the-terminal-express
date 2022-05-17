#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#define MAX_PATH 200

int main(int argc, char const *argv[])
{
    if(argc==2){
        if(!strcmp(argv[1], "help")) {
        printf("\033[0;32m");
        printf("This command only needs one argument to be used: lookaround. It shows all the objects and people on the room you are in.\n");
        printf("\033[0m");
        return 1;
    }
    }

        char cwd[MAX_PATH];
    char folder[10];
    getcwd(cwd, sizeof(cwd));
    int i=0;
    int j=0;
    for(i;i<strlen(cwd);i++) {
        if(cwd[i]=='/') {
            j=i;
        }
    }
    memcpy(folder,&cwd[j+1],strlen(cwd)-j);
    printf("\033[0;35m");
    if(!strcmp(folder,"Luggage_room")){
        printf("You are in the luggage room. Here are stored all the bags and siutcases of all the passengers in the train.");
    }else if (!strcmp(folder,"corridor")){
        printf("You are in the bedrooms wagon.");
    }else if (!strcmp(folder,"Ahmed_room")){
        printf("You are in Ahmeds' bedroom. This is the private area of the passenger called Ahmed.");
    }else if(!strcmp(folder,"Alex_room")){
        printf("You are in Alexs' bedroom. This is the private area of the passenger called Alex.");
    }else if(!strcmp(folder,"Alvaro_room")){
        printf("You are in Alvaros' bedroom. This is the private area of the passenger called Alvaro.");
    }else if(!strcmp(folder,"Edurne_room")){
        printf("You are in Edurnes' bedroom. This is the private area of the passenger called Edurne.");
    }else if(!strcmp(folder,"Millan_room")){
        printf("You are in Millans' bedroom. This is the private area of the passenger called Millan.");
    }else if(!strcmp(folder,"Wiam_room")){
        printf("You are in Wiames' bedroom. This is the private area of the passenger called Wiame.");
    }else if(!strcmp(folder,"restaurant")){
        printf("You are in the trains restaurant wagon. Here all the passengers and staff can take a drink or eat something whenever they want.");
    }else if(!strcmp(folder,"bathroom")){
        printf("You are in the bathroom.");
    }else if(!strcmp(folder,"interrogation_room")){
        printf("You are in the interrogation room. Here is where you must bring the suspects you want to interrogate in order to talk with them.");
    }else if(!strcmp(folder,"smoking_area")){
        printf("You are in the smoking area. This is the only room in which our passengers can smoke, it is forbidden in the rest of the train.");
    }else if(!strcmp(folder,"Crime_scene")){
        printf("You are in the crime scene. Here is where the murder was commited.");
    }else if(!strcmp(folder,"staff_room")){
        printf("You are in the staff room. This is the reservated area for the people who work on this train.");
    }else if(!strcmp(folder,"locomotive")){
        printf("You are now in the locomotive. This is the head of the train, from here all the train is controled.");
    }
    printf("\033[0m");
    printf("\n");
    // get grandparent directory
    char s1[MAX_PATH];
    getcwd(s1,MAX_PATH);
    
    DIR *dir;
    struct dirent *ent;
    dir = opendir(s1);
    if (dir == NULL) {
        printf("\033[0;31m");
        printf("Could not open current directory\n");
        printf("\033[0m");
        return 0;
    }
    while ((ent = readdir(dir)) != NULL) {
        
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            // verify if it is a directory
            if (ent->d_type != DT_DIR) {
            
            printf("%s\n", ent->d_name);}
        }
    }
    closedir(dir);


    return 1;
}
