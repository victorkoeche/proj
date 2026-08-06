#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include "template.h"
#include "filesystem_linux.h"
#include "version.h"

#define SIZE 1000

const char* get_project_name(const char* dir){

    if(dir == NULL){
        errno = EINVAL;
        return NULL;
    }

    const char* project_name = strrchr(dir, '/');

    if(project_name == NULL){
        return dir;
    }

    return project_name + 1;
}

int init_c(const char* dir, char* dir_src, const char* project_name){

    int total_items = 7;
    int skipped = 0;

    int status_readme = generate_from_template(dir, "README.md", project_name);
    int status_makefile = generate_from_template(dir, "Makefile", project_name);
    int status_gitignore = create_file(dir, ".gitignore");
    int status_license = generate_from_template(dir, "LICENSE", project_name);
    int status_src = create_folder(dir, "src");
    int status_include = create_folder(dir, "include");
    int status_main = generate_from_template(dir_src, "main.c", project_name);

    if(status_readme == 1){
        skipped++;
    }

    if(status_readme != 0 && status_readme != 1){
        //printf("Warning: function returned  %d\n", status_readme);
        fprintf(stderr, "Error creating README\n");
   }

    if(status_makefile == 1){
        skipped++;
    }

    if(status_makefile != 0 && status_makefile != 1){
        //printf("Warning: function returned  %d\n", status_makefile);
       fprintf(stderr, "Error creating Makefile\n");
    }

    if(status_gitignore == 1){
        skipped++;
    }

    if(status_gitignore != 0 && status_gitignore != 1){
        //printf("Warning: function returned  %d\n", status_gitignore);
        fprintf(stderr, "Error creating .gitignore\n");
    }

    if(status_license == 1){
        skipped++;
    }

    if(status_license != 0 && status_license != 1){
       //printf("Warning: function returned  %d\n", status_license);
        fprintf(stderr, "Error creating LICENSE\n");
    }

    if(status_main == 1){
        skipped++;
    }

    if(status_main != 0 && status_main != 1){
        //printf("Warning: funcion returned %d\n", status_main);
        fprintf(stderr, "Error creating main.c\n");
    }
            
    if(status_src == 1){
        skipped++;
    }

    if(status_src != 0 && status_src != 1){
        //printf("Warning: function returned  %d\n", status_src);
        fprintf(stderr, "Error creating src/\n");
    }

    if(status_include == 1){
        skipped++;
    }

    if(status_include != 0 && status_include != 1){
        //printf("Warning: function returned  %d\n", status_include);
           fprintf(stderr, "Error creating include/\n");
    }
    

    if(skipped == total_items){
        return 1;
    }else{
        if(status_readme == 1) printf("README already exists. Skipping.\n");
        if(status_makefile == 1) printf("Makefile already exists. Skipping.\n");
        if(status_gitignore == 1) printf(".gitignore already exists. Skipping.\n");
        if(status_license == 1) printf("LICENSE already exists. Skipping.\n");
        if(status_main == 1) printf("main.c already exists. Skipping.\n");
        if(status_src == 1) printf("src/ already exists. Skipping.\n");
        if(status_include == 1) printf("include/ already exists. Skipping.\n");
    }

    return 0;
}

int init_python(const char* dir, char* dir_src, const char* project_name){


    int total_items = 6;
    int skipped = 0;

    int status_readme = generate_from_template(dir, "README.md", project_name);
    int status_requirements = create_file(dir, "requirements.txt");
    int status_gitignore = create_file(dir, ".gitignore");
    int status_license = generate_from_template(dir, "LICENSE", project_name);
    int status_src = create_folder(dir, "src");
    int status_main = generate_from_template(dir_src, "main.py", project_name);

    if(status_readme == 1){
        skipped++;
    }

    if(status_readme != 0 && status_readme != 1){
        //printf("Warning: function returned  %d\n", status_readme);
        fprintf(stderr, "Error creating README\n");
   }

    if(status_requirements == 1){
        skipped++;
    }

    if(status_requirements != 0 && status_requirements != 1){
        //printf("Warning: function returned  %d\n", status_requirements);
       fprintf(stderr, "Error creating requirements.txt\n");
    }

    if(status_gitignore == 1){
        skipped++;
    }

    if(status_gitignore != 0 && status_gitignore != 1){
        //printf("Warning: function returned  %d\n", status_gitignore);
        fprintf(stderr, "Error creating .gitignore\n");
    }

    if(status_license == 1){
        skipped++;
    }

    if(status_license != 0 && status_license != 1){
       //printf("Warning: function returned  %d\n", status_license);
        fprintf(stderr, "Error creating LICENSE\n");
    }

    if(status_main == 1){
        skipped++;
    }

    if(status_main != 0 && status_main != 1){
        //printf("Warning: funcion returned %d\n", status_main);
        fprintf(stderr, "Error creating main.c\n");
    }
            
    if(status_src == 1){
        skipped++;
    }

    if(status_src != 0 && status_src != 1){
        //printf("Warning: function returned  %d\n", status_src);
        fprintf(stderr, "Error creating src/\n");
    }

    if(skipped == total_items){
        return 1;
    }else{
        if(status_readme == 1) printf("README already exists. Skipping.\n");
        if(status_requirements == 1) printf("Makefile already exists. Skipping.\n");
        if(status_gitignore == 1) printf(".gitignore already exists. Skipping.\n");
        if(status_license == 1) printf("LICENSE already exists. Skipping.\n");
        if(status_main == 1) printf("main.c already exists. Skipping.\n");
        if(status_src == 1) printf("src/ already exists. Skipping.\n");
    }

    return 0;
}

int init_project(const char* dir, char* lang){

    if(dir == NULL){
        errno = EINVAL;
        perror("Init project");
        return -1;
    }

    const char* project_name = get_project_name(dir);

    char dir_src[SIZE];

    snprintf(dir_src, sizeof(dir_src), "%s/src", dir);

    if(strcmp(lang, "c") == 0){

        int status_c = init_c(dir, dir_src, project_name);
        if(status_c == 1){
            return 1;
        }
    }else if(strcmp(lang, "python") == 0){

        int status_python = init_python(dir, dir_src, project_name);
        if(status_python == 1){
            return 1;
        }
    }

    printf("Project initialized.\n");
    return 0;
}

int create_project(const char* project_dir, char* lang){

    if(project_dir == NULL){
        errno = EINVAL;
        perror("Error creating project");
        return -1;
    }

    const char* dir = project_dir;

    int status_directory = create_directory(dir);

    if(status_directory != 0 && status_directory != 1){
        //printf("Warning: function returned  %d", status_directory);
        perror("Error creating directory");
        return -1;
    }
    
    return init_project(project_dir, lang);
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