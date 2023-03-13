#include "task.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void task_log(char *name, char *verbed, char *timestr) {
    printf("INFO: Task \"%s\" %s at %s", name, verbed, timestr);
}

/* Build a task and allocate memory */
struct Task *build_task(char *name) {
    struct Task *t = malloc(sizeof(struct Task));
    t->name = name;

    return t;
}

/* Register the start time of a task */
void start_task(struct Task *t) {
    time(&t->start);
    struct tm *timeinfo;
    timeinfo = localtime(&t->start);
    task_log(t->name, "started", asctime(timeinfo));
}

/* Register the end time of a task */
void end_task(struct Task *t) {
    time(&t->end);
    struct tm *timeinfo;
    timeinfo = localtime(&t->end);
    task_log(t->name, "ended", asctime(timeinfo));
    t->finished = 1;
}

/* Run the task */
int run(struct Task *t) {
    start_task(t);
    t->failed = t->run();
    end_task(t);

    return t->failed;
}

char *timestr(time_t ta) {
    struct tm *timea = localtime(&ta);
    char *timea_str = asctime(timea);

    char *p = strchr(timea_str, '\n');
    if (p != NULL) {
        *p = '\0';
    }

    return timea_str;
}

void display(struct Task *t) {
    printf("struct Task {\n");
    printf("    char* name = \"%s\";\n", t->name);
    printf("    time_t start = %ld; // %s\n", t->start, timestr(t->start));
    printf("    time_t end = %ld; // %s\n", t->end, timestr(t->end));
    printf("    int finished = %d;\n", t->finished);
    printf("    int failed = %d;\n", t->failed);
    printf("    int (*run)() = %p;\n", t->run);
    printf("};\n");
}
