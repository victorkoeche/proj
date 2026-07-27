#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "filesystem_linux.h"
#include "project.h"


int main(int argc, char *argv[]){

    int create = 0;
    int arg_dir;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "create") == 0 && i < argc - 1){
            printf("Creating...\n");
            create = 1;
            arg_dir = i + 1;
        }
    }

    if(create == 1){
        create_project(argv[arg_dir]);
    }

    return 0;
}