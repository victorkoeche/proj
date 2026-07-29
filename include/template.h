#ifndef TEMPLATE_H
#define TEMPLATE_H

int replace_placeholder(char *buffer, size_t size, const char* place_holder, const char* value);
int generate_from_template(const char* dir, const char* file_name, const char* project_name);

#endif