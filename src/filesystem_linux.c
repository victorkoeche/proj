#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "filesystem_linux.h"

#define SIZE 100

int create_directory(const char* dir){
    if(dir == NULL){
        errno = EINVAL;
        perror("BUILD-DIRECTORY");
        return -1;
    }

    if(mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0){
        printf("Directory '%s' created successfully.\n", dir);
        return 0;
    }else{
        if(errno == EEXIST){
            perror("create_directory");
            return -2;
        }else{
            perror("Error creating directory");
            return -3;
        }
    }
}

int create_file(const char* dir, const char* arq){
    if(dir == NULL || arq == NULL){
        errno = EINVAL;
        perror("Create File");
        return -1;
    }

    char buffer[SIZE];

    snprintf(buffer, sizeof(buffer), "%s/%s", dir, arq);

    FILE *file = fopen(buffer, "w");
    if(file == NULL){
        perror("Error opening arquive");
        return -1;
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
    create_directory(buffer);
    
    return 0;
}
