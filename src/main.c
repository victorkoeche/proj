#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "filesystem_linux.h"
#define SIZE 100

int main(int argc, char *argv[]){

    if(argc <= 1 || strcmp(argv[1], "proj") == 1){
        fprintf(stderr, "You should call 'proj' in your command as the first token.\n");
        return -1;
    }

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
        int status = create_directory(dir);
    }

    return 0;
}