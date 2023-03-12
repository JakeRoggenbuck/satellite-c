#include <stdio.h>
#include <time.h>

char *time_string() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return asctime(timeinfo);
}
