#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "filesystem_linux.h"

#define SIZE 1000

int init_project(const char* dir){

    if(dir == NULL){
        errno = EINVAL;
        perror("Init project");
        return -1;
    }

    int total_items = 6;
    int skipped = 0;
    char buffer[SIZE];

    snprintf(buffer, sizeof(buffer), "%s/README.md", dir);

    if(path_exists(buffer)){
        printf("README.md already exists. Skipped.\n");
        skipped++;
    }else{
        int status_readme = create_file(dir, "README.md");

        if(status_readme != 0){
            //printf("Warning: function returned  %d\n", status_readme);
            perror("Error creating README");
        }
    }

    snprintf(buffer, sizeof(buffer), "%s/Makefile", dir);

    if(path_exists(buffer)){
        printf("Makefile already exists. Skipped.\n");
        skipped++;
    }else{
        int status_makefile = create_file(dir, "Makefile");

        if(status_makefile != 0){
            //printf("Warning: function returned  %d\n", status_makefile);
            perror("Error creating Makefile");
        }
    }

    snprintf(buffer, sizeof(buffer), "%s/.gitignore", dir);

    if(path_exists(buffer)){
        printf(".gitignore already exists. Skipped.\n");
        skipped++;
    }else{
        int status_gitignore = create_file(dir, ".gitignore");

        if(status_gitignore != 0){
            //printf("Warning: function returned  %d\n", status_gitignore);
            perror("Error creating .gitignore");
        }
    }

    snprintf(buffer, sizeof(buffer), "%s/LICENSE", dir);

    if(path_exists(buffer)){
        printf("LICENSE already exists. Skipped.\n");
        skipped++;
    }else{
        int status_license = create_file(dir, "LICENSE");

        if(status_license != 0){
            //printf("Warning: function returned  %d\n", status_license);
            perror("Error creating LICENSE");
        }
    }

    snprintf(buffer, sizeof(buffer), "%s/src/", dir);

    if(path_exists(buffer)){
        printf("src/ already exists. Skipped.\n");
        skipped++;
    }else{
        int status_src = create_folder(dir, "src");
            
        if(status_src != 0){
            //printf("Warning: function returned  %d\n", status_src);
            perror("Error creating src/");
        }
    }

    snprintf(buffer, sizeof(buffer), "%s/include/", dir);

    if(path_exists(buffer)){
        printf("include/ already exists. Skipped.\n");
        skipped++;
    }else{
        int status_include = create_folder(dir, "include");

        if(status_include != 0){
            //printf("Warning: function returned  %d\n", status_include);
            perror("Error creating include/");
        }
    }

    if(skipped == total_items){
        printf("\nProject already initialized.\nNothing to do.\n");
        return 0;
    }

    return 0;

}

int create_project(const char* project_dir){

    if(project_dir == NULL){
        errno = EINVAL;
        perror("Error creating project");
        return -1;
    }

    const char* dir = project_dir;

    int status_directory = create_directory(dir);

    if(status_directory != 0){
        //printf("Warning: function returned  %d", status_directory);
        perror("Error creating directory");
        return -1;
    }
    
    return init_project(project_dir);
}