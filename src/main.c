#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "filesystem_linux.h"
#include "project.h"


int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Sorry, too few arguments. Try: 'proj -help'.\n");
        return 1;
    }


    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "create") == 0){
            if(i < argc - 1){
                printf("Creating...\n");
                return create_project(argv[i + 1]);
            }else{
                printf("Sorry, too few arguments. Try: 'proj -help'.\n");
                return 1;
            }
        }
        else if(strcmp(argv[i], "init") == 0){
            if(i < argc - 1){
                printf("Did you mean 'create' instead of 'init'? [Y/n]\n");
                char input;
                scanf(" %c", &input);
                if(input == 'Y' || input == 'y'){
                    return create_project(argv[i + 1]);
                }else{
                    printf("Sorry, 'init' does not accept any arguments. Try: 'proj -help'.\n");
                    return 1;
                }
            }
            printf("Initializing...\n\n");
            return init_project(".");
        }else{
            printf("Unknown command: %s.\nTry:\n 'proj -help'\n", argv[i]);
            return 1;
        }
    }


    return 0;
}