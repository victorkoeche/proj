#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "commands.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Sorry, too few arguments.Try 'proj --help'.\n");
        return 1;
    }

    if (strcmp(argv[1], "create") == 0) {
        return handle_create(argc, argv);
    }

    if (strcmp(argv[1], "init") == 0) {
        return handle_init(argc, argv);
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        handle_help();
        return 0;
    }

    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        handle_version();
        return 0;
    }

    fprintf(stderr, "Unknown command: %s\n", argv[1]);
    return 1;
}