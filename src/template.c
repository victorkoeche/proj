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

    strncpy(buffer, temp, size);

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

    // TODO: resolve template path relative to the executable location

    snprintf(template_path, sizeof(template_path), "./templates/%s.template", file_name);
    snprintf(file_path, sizeof(file_path), "%s/%s", dir, file_name);

    int status = create_file(dir, file_name);

    if(status != 0){
        return status;
    }

    FILE *file_read = fopen(template_path, "r");

    if(file_read == NULL){
        return -2;
    }

    FILE *file_write = fopen(file_path, "w");

    if(file_write == NULL){
        fclose(file_read);
        return -2;
    }

    char buffer[SIZE];

    while(fgets(buffer, sizeof(buffer), file_read) != NULL){
        if(strstr(buffer, "{{PROJECT_NAME}}")){
            replace_placeholder(buffer, sizeof(buffer), "{{PROJECT_NAME}}", project_name);
        }
        fputs(buffer, file_write);
    }

    fclose(file_read);
    fclose(file_write);

    return 0;   
}