/* err_manager.h */
#ifndef ERR_MANAGER_H
#define ERR_MANAGER_H

#include <stdio.h>   // fprintf, stderr
#include <errno.h>   // errno
#include <string.h>  // strerrors


/**
 * @brief why this file ?
 * 
 * -> make a minimal StackTrace in C to see clear errors
 * 
 * pros :
 * - no need framework
 * - fast
 * - no configuration
 * - eazy to use
 * 
 * cons :
 * - heavy, manual update on stackTrace (need to write Err_PUSH/POP on every function that
 * can potentially fail)
 * - difficult when writing on multi-threaded and/or
 * concurrent/parallel programming (but can evolve to this way)
 * 
 * 
 */


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
 * @version v2
 */
typedef struct StackTraceLink StackTraceLink;
struct StackTraceLink{
    const char* msg;
    const char* file;
    int line;
    const char* caller;
}; 

/**
 * @brief to use instead of `perror()` to get 
 * mode details about an error
 * @note to improve function may add 
 * @version v2
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

void err_push_StackTrace(const char* file, int line, const char* caller);
void err_pop_StackTrace();

/**
 * @brief preprocessor macro to make the stuff working under the hood 
 * much clear and eazy to understand.
 * @version v2
 * 
 * - __FILE__
 * 
 * - __Line__
 * 
 * - __func__
 * 
 * @note optional to write ERR_PUSH... and ERR_POP... on the function
 * that call `ERR_TERROR(msg)`
 */
#define ERR_TERROR(msg) __err_terror(msg, __FILE__, __LINE__, __func__)

/**
 * @brief must be initialized after each function 
 * @version v2
 * 
 * @warning to call after each function signature that use TERROR later in the code
 */
#define ERR_PUSH_STACKTRACE() err_push_StackTrace(__FILE__, __LINE__-1, __func__)

/**
 * @brief must be written after each function that use later TERROR
 * @version v2
 * 
 * @warning to call before each function ends that use TERROR later in the code
 */
#define ERR_POP_STACKTRACE() err_pop_StackTrace()


#endif

// end page
