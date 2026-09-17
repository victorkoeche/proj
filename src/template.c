#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "template.h"
#include "filesystem_linux.h"
#include "project.h"

#define SIZE 1000

int replace_placeholder(char* buffer, size_t size, const char* place_holder, const char* value){

    if(buffer == NULL || place_holder == NULL || value == NULL){
        errno = EINVAL;
        return -1;
    }

    char* pointer = strstr(buffer, place_holder);

    if(pointer == NULL){
        return 1;
    }

    char temp[SIZE];

    int prefix_size = pointer - buffer;

    snprintf(temp, sizeof(temp), "%.*s%s%s", prefix_size, buffer, value, pointer + strlen(place_holder));

    strncpy(buffer, temp, size - 1);
    buffer[size - 1] = '\0';

    return 0;
}

int generate_from_template(const char* dir, const char* file_name, const char* project_name){

    if(dir == NULL || file_name == NULL){
        errno = EINVAL;
        perror("Generate From Template");
        return -1;
    }

    char template_path[SIZE];
    char file_path[SIZE];

    const char* home = getenv("HOME");

    if (home == NULL) {
        errno = ENOENT;
        perror("HOME");
        return -1;
    }

    snprintf(template_path, sizeof(template_path),"%s/.local/share/proj/templates/%s.template",home,file_name);
    snprintf(file_path, sizeof(file_path), "%s/%s", dir, file_name);

    if(path_exists(file_path)){
        return 1;
    }

    FILE *file_read = fopen(template_path, "r");

    if(file_read == NULL){
        perror("Template read");
        return -2;
    }

    FILE *file_write = fopen(file_path, "w");

    if(file_write == NULL){
        perror("Destination file create");
        fclose(file_read);
        return -2;
    }

    char buffer[SIZE];

    while(fgets(buffer, sizeof(buffer), file_read) != NULL){
        while(replace_placeholder(buffer, sizeof(buffer), "{{PROJECT_NAME}}", project_name) == 0);
        fputs(buffer, file_write);
    }

    fclose(file_read);
    fclose(file_write);

    return 0;   
}