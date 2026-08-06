#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "project.h"
#include "version.h"

char* get_valid_lang(char* lang){

    if(lang == NULL){
        errno = EINVAL;
        perror("Language");
        return NULL;
    }

    char* returnlang;

    if(strcmp(lang, "C") == 0 || strcmp(lang, "c") == 0){
        returnlang = "c";
    }else if(strcmp(lang, "Python") == 0 || strcmp(lang, "python") == 0){
        returnlang = "python";
    }else{
        printf("Invalid Language.\n");
        return NULL;
    }

    return returnlang;
}

int handle_create(int argc, char* argv[]){

    printf("Creating...\n");

    int status = -1;

    if(argc == 3){
        status = create_project(argv[2], "c");
    }else if(argc == 5 && strcmp(argv[3],"--lang") == 0){
        char *lang = get_valid_lang(argv[4]);
        if(lang != NULL){
            status = create_project(argv[2], lang);
        }else{
            printf("Sorry, '%s' is not a valid language. Try 'proj --help'.", argv[4]);
            return 1;
        }
    }

    if(status == 1){
        printf("Project already created.\nNothing to do.\n");
        return 1;

    }else if(status == 0){
        return 0;
    }else{
        perror("Failed to create project.");
        return -1;
    }

    return 0;
}

int handle_init(int argc, char* argv[]){

    printf("Initializing...\n");

    int status = -1;

    if(argc == 2){
        status = init_project(".", "c");
    }else if(argc == 4 && strcmp(argv[2], "--lang") == 0){
        char* lang = get_valid_lang(argv[3]);
        if(lang != NULL){
            status = init_project(".", lang);
        }else{
            printf("Sorry, '%s' is not a valid language. Try 'proj --help'.", argv[3]);
        }
    }

    if(status == 1){
        printf("Project already initialized.\nNothing to do.\n");
        return 1;
    }else if(status == 0){
        return 0;
    }else{
        perror("Failed to initialize project");
        return -1;
    }

    return 0;
}

int handle_version(){

    printf("proj version %s\n", PROJ_VERSION);

    return 0;
}

int handle_help(){

    show_help();

    return 0;
}
