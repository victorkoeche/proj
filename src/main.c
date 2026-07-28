#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "filesystem_linux.h"
#include "project.h"


int main(int argc, char *argv[]){


    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "create") == 0 && i < argc - 1){
            printf("Creating...\n");
            create_project(argv[i + 1]);
        }
        else if(strcmp(argv[i], "init") == 0){
            printf("Initializing...\n\n");
            init_project(".");
        }
    }


    return 0;
}