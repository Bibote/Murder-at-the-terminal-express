#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
#include <dirent.h>
#define MAX_PATH 200

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
            if (strcmp(argv[1],"help")==0)
            
        {   printf("\033[0;32m");
            printf("This command is used without arguments\n");
            printf("It will show:\n\tThe current room\n\tRooms directly accesible from the current room\n\tA simple map of the train");
            printf("\n\n");
            printf("Press a key to continue");
            getchar();
            printf("\033[0m");
            system("clear");
            return 1;
        }
        else
        {   printf("\033[0;31m");
            printf("Wrong ammount of parameters");
            printf("\033[0m");
            return 0;
        }
    }
    
 
    printf("                _ _ _        _ _ _                    _ _ _ _ \n");
    printf("               | Marc |     | Alex |      _ _ _ _    | Alvaro |      		                            _ _ _ _ _ _ _ _\n");
    printf("               | room |     | room |     | Ahmed |   |  room  |      			                       |               |\n");
    printf("               |_ _ _ |     |_ _ _ |     | room  |   |_ _ _ _ |      			                       |  smoking room |\n");
    printf("                  ^            ^         |_ _ _ _|       ^           			                       |_ _ _ _ _ _ _ _|\n");
    printf("                   \\            \\          ^          //                     			                    ^\n");
    printf("                        \\          \\       |       //                      	 			                |\n");
    printf("                             \\        \\    |    //                           			                    |\n");
    printf("                                 \\       \\ | //                            	 			                |\n");
    printf("       _ _ _ _ _ _ _ _ _ _            \\ _ _ _ _ _                       _ _ _ _ _ _                _ _ _ _ _ _ _               _ _ _ _ _ _ _                _ _ _ _ _ _                _ _ _ _ _ _ \n");
    printf("      |                   |             |          |                    |            |             |interrogation|             |              |             |            |             |            |\n");
    printf("	  |    Luggageroom    | ==========> | Corridor | =================> | Restaurant | ==========> |room         | ==========> | Crime scene  | ==========> | Staff room | ==========> | Locomotive |\n");
    printf("	  |_ _ _ _ _ _ _ _ _ _|             |_ _ _ _ _ |                    |_ _ _ _ _ _ |             |_ _ _ _ _ _ _|             |_ _ _ _ _ _ _ |             |_ _ _ _ _ _ |             |_ _ _ _ _ _ |\n");
    printf("                                          // | \\                              |\n");
    printf("                                       //    |    \\                           |\n");
    printf("                                    //       |       \\                        |\n");
    printf("                                 //          v          \\                     v\n");
    printf("                                v        _ _ _ _ _        v               _ _ _ _ _ \n");
    printf("                            _ _ _ _     |  Millan |    _ _ _ _           |          |\n");
    printf("                           | Edurne |   |  room   |   | Wiame |          | Bathroom |\n");
    printf("                           |  room  |   |_ _ _ _ _|   | room  |          |_ _ _ _ _ |\n");
    printf("                           |_ _ _ _ |                 |_ _ _ _|\n");

    //get name of the current directory
    char s0[MAX_PATH];
    getcwd(s0,MAX_PATH);
    char *n = strrchr(s0, '/');
    printf("You are in: %s\n",n);
    // get grandparent directory
    printf("\nYou can go to:\n\n");
    char s1[MAX_PATH];
    getcwd(s1,MAX_PATH);
    char s2[MAX_PATH];
    getcwd(s2,MAX_PATH);
    char *p = strrchr(s2, '/');
    *p = '\0';
    p = strrchr(s2, '/');
    *p = '\1';
    printf("%s\n",p);
    // get same level directories
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
            if (ent->d_type == DT_DIR) {
            
            printf("%s\n", ent->d_name);}
        }
    }
    closedir(dir);

    

    



    
    return 1;
}
