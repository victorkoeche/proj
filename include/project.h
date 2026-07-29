#ifndef PROJECT_H
#define PROJECT_H

const char* get_project_name(const char* dir);
int init_project(const char* dir);
int create_project(const char* project_name);
void show_help(void);

#endif