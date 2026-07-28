#ifndef FILESYSTEM_LINUX_H
#define FILESYSTEM_LINUX_H

int path_exists(const char* path);
int create_directory(const char* dir);
int create_file(const char* dir, const char* arq);
int create_folder(const char* dir, const char* folder);

#endif