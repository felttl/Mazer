/* err_manager.c */
#include "../../include/utils/err_manager.h"
#include <stdlib.h> // exit(), EXIT_FAILURE


void terror(const char* msg, const char* file, int line, const char* caller){
    const char red_bold[] = "\033[1;91m";
    const char reset[] = "\x1B[0m";
    // Appliquer la couleur directement à stderr
    fprintf(stderr, "%s", red_bold);
    fprintf(stderr, "[ERROR] %s:%d\n", file, line);
    fprintf(stderr, "\t(called from %s) : %s\n", caller, msg);
    fprintf(stderr, "%s", reset);
    exit(EXIT_FAILURE);
}

// end page
