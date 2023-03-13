#include "log.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#define DISPLAY_LOGS

char *LOGPATH = "logfile.txt";

FILE *open_log(char *filepath) {
    static FILE *p;
    p = fopen(filepath, "a");
    return p;
}

void LOGT(enum Severity s, time_t t, char *msg) {
    if (s == FATAL) {
        exit(1);
    }

    FILE *logfile = open_log(LOGPATH);
    char *ts = timestr(t);

    char buf[300];
    sprintf(buf, "%s: [%s] %s\n", severity_name(s), ts, msg);
    fputs(buf, logfile);
    fclose(logfile);

#ifdef DISPLAY_LOGS
    printf("%s", buf);
#endif
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
