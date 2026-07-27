#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "filesystem_linux.h"

int create_project(const char* project_name){

    if(project_name == NULL){
        errno = EINVAL;
        perror("Error creating project");
        return -1;
    }

    const char* dir = project_name;
    int errors_found = 0;

    int status_directory = create_directory(dir);

    if(status_directory != 0){
        printf("Warning: function returned  %d", status_directory);
        perror("Error creating directory");
        return -1;
    }
    
    int status_readme = create_file(dir, "README.md");

    if(status_readme != 0){
        printf("Warning: function returned  %d", status_readme);
        errors_found++;
        perror("Error creating README");
    }

    int status_makefile = create_file(dir, "Makefile");

    if(status_makefile != 0){
        printf("Warning: function returned  %d", status_makefile);
        errors_found++;
        perror("Error creating Makefile");
    }


    int status_gitignore = create_file(dir, ".gitignore");

    if(status_gitignore != 0){
        printf("Warning: function returned  %d", status_gitignore);
        errors_found++;
        perror("Error creating .gitignore");
    }

    int status_license = create_file(dir, "LICENSE");

    if(status_license != 0){
        printf("Warning: function returned  %d", status_license);
        errors_found++;
        perror("Error creating LICENSE");
    }

    int status_src = create_folder(dir, "src");
        
    if(status_src != 0){
        printf("Warning: function returned  %d", status_src);
        errors_found++;
        perror("Error creating src/");
    }

    int status_include = create_folder(dir, "include");

    if(status_include != 0){
        printf("Warning: function returned  %d", status_include);
        errors_found++;
        perror("Error creating include/");
    }

    if(errors_found){
        printf("Operation returned with %d problems", errors_found);
        return 1;
    }

    return 0;
}