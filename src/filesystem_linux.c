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

int create_readme(const char* dir){
    if(dir == NULL){
        errno = EINVAL;
        perror("Create README");
        return -1;
    }

    char buffer[SIZE];

    snprintf(buffer, sizeof(buffer), "%s/README.md", dir);

    FILE *readme = fopen(buffer, "w");
    if(readme == NULL){
        perror("Error opening README.md");
        return -1;
    }

    fclose(readme);

    return 0;
}
