/* err_manager.c */
#include "../../include/utils/err_manager.h"
#include <stdlib.h> // exit(), EXIT_FAILURE


void terror(const char* msg){
    LOG_ERROR(msg);
    perror(msg);
    exit(EXIT_FAILURE);
}


// end page
