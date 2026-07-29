#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "filesystem_linux.h"
#include "version.h"

#define SIZE 1000

int init_project(const char* dir){

    if(dir == NULL){
        errno = EINVAL;
        perror("Init project");
        return -1;
    }

    int total_items = 6;
    int skipped = 0;

    int status_readme = create_file(dir, "README.md");
    int status_makefile = create_file(dir, "Makefile");
    int status_gitignore = create_file(dir, ".gitignore");
    int status_license = create_file(dir, "LICENSE");
    int status_src = create_folder(dir, "src");
    int status_include = create_folder(dir, "include");

        if(status_readme == 1){
            skipped++;
        }

        if(status_readme != 0 && status_readme != 1){
            //printf("Warning: function returned  %d\n", status_readme);
            fprintf(stderr, "Error creating README");
        }

        if(status_makefile == 1){
            skipped++;
        }

        if(status_makefile != 0 && status_makefile != 1){
            //printf("Warning: function returned  %d\n", status_makefile);
            fprintf(stderr, "Error creating Makefile");
        }

        if(status_gitignore == 1){
            skipped++;
        }

        if(status_gitignore != 0 && status_gitignore != 1){
            //printf("Warning: function returned  %d\n", status_gitignore);
            fprintf(stderr, "Error creating .gitignore");
        }

        if(status_license == 1){
            skipped++;
        }

        if(status_license != 0 && status_license != 1){
            //printf("Warning: function returned  %d\n", status_license);
            fprintf(stderr, "Error creating LICENSE");
        }
        
        if(status_src == 1){
            skipped++;
        }

        if(status_src != 0 && status_src != 1){
            //printf("Warning: function returned  %d\n", status_src);
            fprintf(stderr, "Error creating src/");
        }

        if(status_include == 1){
            skipped++;
        }

        if(status_include != 0 && status_include != 1){
            //printf("Warning: function returned  %d\n", status_include);
            fprintf(stderr, "Error creating include/");
        }

    if(skipped == total_items){
        printf("Project already initialized.\nNothing to do.\n");
        return 0;
    }else{
        if(status_readme == 1) printf("README already exists. Skipping.\n");
        if(status_makefile == 1) printf("Makefile already exists. Skipping.\n");
        if(status_gitignore == 1) printf(".gitignore already exists. Skipping.\n");
        if(status_license == 1) printf("LICENSE already exists. Skipping.\n");
        if(status_src == 1) printf("src/ already exists. Skipping.\n");
        if(status_include == 1) printf("include/ already exists. Skipping.\n");
    }

    printf("Project initialized.\n");
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

void show_help(void)
{
    printf(
        "\n"
        "┌─────────────────────────────────────────────┐\n"
        "│                  PROJ v%s                │\n"
        "│      A simple project scaffolding tool      │\n"
        "└─────────────────────────────────────────────┘\n"
        "\n"
        "USAGE\n"
        "    proj <command> [options]\n"
        "\n"
        "COMMANDS\n"
        "    create <name>    Create a new project\n"
        "    init             Initialize current directory\n"
        "    help             Show help information\n"
        "\n"
        "OPTIONS\n"
        "    -h, --help       Show help\n"
        "    -v, --version    Show version\n"
        "\n"
        "EXAMPLES\n"
        "    proj create my_app\n"
        "    proj init\n"
        "\n"
        "For more information:\n"
        "    github.com/victorkoeche/proj\n"
        "\n"
    , PROJ_VERSION);
}