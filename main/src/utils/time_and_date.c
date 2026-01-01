/* time_and_date.c */
#include "../../include/utils/time_and_date.h"
#include <time.h>

/**
 * @author Félix TTL
 * @date 24/12/2023 - 9/1/2024 14h40 (2:40 pm) (V1)
 * @date dec 2025
 * @version V2
 * @project_name : Mazer
 */

double get_time_sec() {
    #if defined(__APPLE__)
        // macOS: utiliser CLOCK_MONOTONIC si disponible
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return ts.tv_sec + ts.tv_nsec / 1e9;
    #else
        // Linux et autres Unix
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return ts.tv_sec + ts.tv_nsec / 1e9;
    #endif
}