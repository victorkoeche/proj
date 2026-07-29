#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "filesystem_linux.h"
#include "project.h"
#include "template.h"
#include "version.h"

int main(int argc, char *argv[]){

    if(argc <= 1){
        printf("Sorry, too few arguments. Try: 'proj --help'.\n");
        return 1;
    }


    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "create") == 0){
            if(i < argc - 1){
                printf("Creating...\n");
                int status = create_project(argv[i + 1]);
                if(status == 1){
                    printf("Project '%s' already exists.\n", argv[i + 1]);
                    printf("Use 'proj init' inside that directory if you want to initialize it.\n");
                    return 1;
                }else if(status == 0){
                    return 0;
                }else{
                    perror("Failed to create project");
                    return -1;
                }
            }else{
                printf("Sorry, too few arguments. Try: 'proj --help'.\n");
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
                    printf("Sorry, 'init' does not accept any arguments. Try: 'proj --help'.\n");
                    return 1;
                }
            }
            printf("Initializing...\n");
            return init_project(".");
        }
        else if(strcmp(argv[i], "--help")== 0 || strcmp(argv[i], "-h") == 0){
            show_help();
            return 0;
        }else if(strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0){
            printf("proj version %s\n", PROJ_VERSION);
        }else{
            printf("Unknown command: %s.\nTry:\n 'proj --help'\n", argv[i]);
            return 1;
        }
    }


    return 0;
}