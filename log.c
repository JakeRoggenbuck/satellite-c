#include "log.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

char *LOGPATH = "logfile.txt";

FILE *open_log(char *filepath) {
    static FILE *p;
    p = fopen(filepath, "a");
    return p;
}

void LOGT(enum Severity s, time_t t, char *msg) {
    FILE *logfile = open_log(LOGPATH);

    char *ts = timestr(t);

    fputs(severity_name(s), logfile);
    fputs(": [", logfile);
    fputs(ts, logfile);
    fputs("]: ", logfile);
    fputs(msg, logfile);
    fputs("\n", logfile);
    fclose(logfile);
}

void LOG(enum Severity s, char *msg) {
    time_t a;
    time(&a);
    LOGT(s, a, msg);
}

char *severity_name(enum Severity s) {
    static char *names[] = {"INFO", "DEBUG", "WARNING", "ERROR"};
    return names[s];
}
