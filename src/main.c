#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "filesystem_linux.h"
#define SIZE 100

int main(int argc, char *argv[]){

    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);

    int create = 0;
    int edit = 0;
    int delete = 0;
    char buffer[SIZE];
    int arg_dir;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "create") == 0 && i < argc - 1){
            printf("Creating...\n");
            create = 1;
            arg_dir = i + 1;
        }
        else if(strcmp(argv[i], "edit") == 0){
            printf("Editing...\n");
            edit = 1;
        }
        else if(strcmp(argv[i], "delete") == 0){
            printf("Deleting...\n");
            delete = 1;
        }
    }

    if(create == 1){
        char* dir = strcpy(buffer, argv[arg_dir]);
        int status_directory = create_directory(dir);
        int status_readme = create_readme(dir);
    }

    return 0;
}