/* err_manager.h */
#ifndef ERR_MANAGER_H
#define ERR_MANAGER_H

#include <stdio.h>   // fprintf, stderr
#include <errno.h>   // errno
#include <string.h>  // strerrors

/**
 * @brief store a level of information (to see the full StackTrace errors "in-depth")
 * 
 * - msg `const char*` : message from the system to see precisely the error
 * 
 * - file `const char*` : the file where an event occurend (for the final error)
 * 
 * - line `int` : the number of the line in the file where the code throw an event
 * 
 * - caller `const char*` : where the function that throw the event was
 * 
 */
typedef struct StackTraceLink StackTraceLink;
struct StackTraceLink{
    const char* msg;
    const char* file;
    int line;
    const char* caller;
}; 


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
#define TERROR(msg) __err_terror(msg, __FILE__, __LINE__, __func__)

/**
 * @brief must be initialized after each function 
 * 
 * @warning initialized after each function signature that use TERROR later in the code
 */
#define ERR_PUSH_STACKTRACE() err_push_StackTrace(__FILE__, __LINE__, __func__)

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
void __err_terror(const char* msg, const char* file, int line, const char* caller);

#endif

// end page
