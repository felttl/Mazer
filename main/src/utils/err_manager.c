/* err_manager.c */
#include "../../include/utils/err_manager.h"
#include <stdlib.h> // exit(), EXIT_FAILURE, free()
#include <execinfo.h> // backtrace(), backtrace_symbols()
#include <stdio.h>     // fprintf()
#include <dlfcn.h>    // dladdr, Dl_info
#include "../../include/utils/Stack.h"

/**
 * @brief internal stackTrace 
 * (faster to understand errors)
 */
static Stack* StackTrace = NULL;

/* called once, internal function */
void __err_init_StackTrace(){
    // impossible : ERR_PUSH_STACKTRACE();
    if(StackTrace == NULL)
        StackTrace = sk_create((StackTraceLink*)NULL);
    // impossible : ERR_POP_STACKTRACE();
}

void err_push_StackTrace(const char* file, int line, const char* caller){
    __err_init_StackTrace();
    StackTraceLink* link = malloc(sizeof(StackTraceLink));
    link->msg = NULL;  // pas de message pour ce push
    link->file = file;
    link->line = line;
    Stack* nodeStack = sk_create(link);
    sk_push(StackTrace, nodeStack);
}

void err_pop_StackTrace(){
    if(!StackTrace || StackTrace->sk_size == 0) return;
    StackTraceLink* link = (StackTraceLink*) sk_pop(StackTrace);
    free(link);
}

/* internal function */
void __err_show_1lvl(const char* msg, const char* file, int line, const char* caller){
    const char red_bold[] = "\033[1;91m";
    const char reset[] = "\x1B[0m";
    // Appliquer la couleur directement à stderr
    fprintf(stderr, "%s", red_bold);
    fprintf(stderr, "[ERROR] %s:%d\n", file, line);
    fprintf(stderr, "\t(called from %s) : %s\n", caller, msg ? msg : "<no message>");
    fprintf(stderr, "%s", reset);
}

/* internal function */
void __err_terror(const char* msg, const char* file, int line, const char* caller){
    // show all levels
    Stack* nodeStack;
    StackTraceLink* current;
    while(StackTrace->sk_size > 0){
        nodeStack = sk_pop(StackTrace);
        if(!nodeStack) continue;
        current = (StackTraceLink*) sk_pop(StackTrace);
        __err_show_1lvl(current->msg,current->file,
            current->line,current->caller
        );
        free(current);
        free(nodeStack);
    }
    __err_show_1lvl(msg,file,line,caller);
    exit(EXIT_FAILURE);
}

// end page
