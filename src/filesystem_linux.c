#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "filesystem_linux.h"

#define SIZE 1000

int path_exists(const char* path){

    if(path == NULL){
        errno = EINVAL;
        perror("Path verify");
        return -1;
    }

    struct stat buffer;

    return(stat(path, &buffer) == 0);
}

int create_directory(const char* dir){

    if(dir == NULL){
        errno = EINVAL;
        perror("Create directory");
        return -1;
    }

    if(path_exists(dir)){
        errno = EEXIST;
        return 1;
    }

    if(mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0){
        printf("Directory '%s' created successfully.\n", dir);
        return 0;
    }else{
        return -2;
    }
}

int create_file(const char* dir, const char* arq){

    if(dir == NULL || arq == NULL){
        return -1;
    }

    char buffer[SIZE];

    snprintf(buffer, sizeof(buffer), "%s/%s", dir, arq);

    FILE *file = fopen(buffer, "w");
    if(file == NULL){
        return -2;
    }

    fclose(file);

    return 0;
}

int create_folder(const char* dir, const char* folder){

    if(dir == NULL || folder == NULL){
        errno = EINVAL;
        perror("Create Folder");
        return -1;
    }

    char buffer[SIZE];

    snprintf(buffer, sizeof(buffer), "%s/%s", dir, folder);

   return create_directory(buffer);
}
