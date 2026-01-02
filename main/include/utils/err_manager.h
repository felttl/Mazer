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
#define TERROR(msg) terror(msg, __FILE__, __LINE__, __func__)

/**
 * @brief to use instead of `perror()` to get 
 * mode details about an error
 * @note to improve function may add 
 * 
 * Stack structure to create StackTrace 
 * 
 * of errors to log the path of the errors 
 * 
 * across the whole app and all programs
 * 
 * in later versions...
 */
void terror(const char* msg, const char* file, int line, const char* caller);

#endif

// end page
