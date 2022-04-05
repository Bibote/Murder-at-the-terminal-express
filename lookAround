#include <sys/types.h>
#include <dirent.h>

int lookAround(char dirname[], char const *ext)

{
    printf("In this room you can see:");
    DIR * d;
    struct dirent *dir;

    d = opendir(dirname);

    if (d != NULL)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (has_extension(dir->d_name, ext))
            {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }
    return(0);
}


const char* acutalDir(){
    char path[] = pwd();

    char linea[PATH_MAX];
    getcwd(linea, PATH_MAX);
    //char *realpath(const char *path, char *resolved_path);

    //Directorio actual char *getcwd(char *buf, size_t size);

    /*int i = 0;
    char *p = strtok (path, "/");
    char *array[252];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "/");
    }
    return array[i];*/
    return path;
}