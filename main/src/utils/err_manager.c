/* err_manager.c */
#include "../../include/utils/err_manager.h"
#include <stdlib.h> // exit(), EXIT_FAILURE, free()
#include <execinfo.h> // backtrace(), backtrace_symbols()
#include <stdio.h>     // fprintf()
#include <dlfcn.h>    // dladdr, Dl_info
#include "../../include/utils/Stack.h"

/**
 * on ne garde pas l'idée de plusieurs étages pour l'instant
 * on fait en sorte que ça fonctionne pour le reste on verra plus tar
 * 
 */


static Stack* StackTrace = NULL;

/* called once */
void err_manager_init(){
    if(StackTrace == NULL)
        StackTrace = sk_create((StackTraceLink*)NULL);
}

void err_push_StackTrace(const char* file, int line, const char* caller){
    init_stack_trace();

    // créer le node
    StackTraceLink* link = malloc(sizeof(StackTraceLink));
    link->msg = NULL;  // pas de message pour ce push
    link->file = file;
    link->line = line;
    link->caller = caller;

    // empiler
    Stack* nodeStack = sk_create(link);
    sk_push(StackTrace, nodeStack);
}

void err_pop_StackTrace(){
    // ... // a construire 
}

/* internal function */
void __err_show_1lvl(const char* msg, const char* file, int line, const char* caller){
    const char red_bold[] = "\033[1;91m";
    const char reset[] = "\x1B[0m";
    // Appliquer la couleur directement à stderr
    fprintf(stderr, "%s", red_bold);
    fprintf(stderr, "[ERROR] %s:%d\n", file, line);
    fprintf(stderr, "\t(called from %s) : %s\n", caller, msg);
    fprintf(stderr, "%s", reset);
}

/* internal function */
void __err_terror(const char* msg, const char* file, int line, const char* caller){
    // show all levels 
    StackTraceLink* current;
    while(StackTrace->index > 0){
        current = (StackTraceLink*) sk_pop(StackTrace);
        __err_show_1lvl(current->msg,current->file,
            current->line,current->caller
        );
    }
    __err_show_1lvl(msg,file,line,caller);
    exit(EXIT_FAILURE);
}

// end page
