
int talk(char nombre[],char about[]) {
    char archivo[50];
    int offset;
    FILE *fp;
    printf("Using talk function");
    if(!strcmp(nombre, "Millan")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Millan.txt","r");
    }
    else if(!strcmp(nombre, "Ahmed")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Ahmed.txt","r");
    }else if(!strcmp(nombre, "Alex")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Alex.txt","r");
    }else if(!strcmp(nombre, "Alvaro")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Alvaro.txt","r");
    }else if(!strcmp(nombre, "Wiam")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Wiam.txt","r");
    }else if(!strcmp(nombre, "Edurne")) {
        fp = fopen("launch directory/Crime scene/Staffroom/LoungeRoom/Edurne.txt","r");
    }
    else {
        printf("There is no one with that name");
        return 0;
    }
    if (fp == NULL) {
        printf("wrong path");
        return 0;
    }
    if(!strcmp(about, "physical")) {
        offset=0;
    }
    else if(!strcmp(about, "moral")) {
        offset=32;
    }
    else if(!strcmp(about, "Identity")) {
        offset=52;
    }
    else if(!strcmp(about, "accusation")) {
        offset=52;
    }
    else {
        printf("They wont talk about that");
        return 0;
    }
    fseek( fp, offset, 1 );
    do {
        // Taking input single character at a time
        char c = fgetc(fp);
 
        // Checking for end of file
        if (feof(fp) || c=='.')
            break;
 
        printf("%c", c);

    } while(1);
    fclose(fp);
    return(1);


}