/* err_manager.h */
#ifndef ERR_MANAGER_H
#define ERR_MANAGER_H

#include <stdio.h>   // fprintf, stderr
#include <errno.h>   // errno
#include <string.h>  // strerrors

/**
 * @brief preprocessor macro reminder
 * 
 * - __FILE__
 * 
 * - __Line__
 * 
 * - __func__
 * 
 * 
 */
#define LOG_ERROR(msg) \
    fprintf(stderr, "[ERROR] %s:%d (%s) : %s | errno=%d (%s)\n", \
        __FILE__, __LINE__, __func__, msg, errno, strerror(errno))

/**
 * @brief on error SIG
 * 
 */
void terror(const char* msg);

#endif

// end page
