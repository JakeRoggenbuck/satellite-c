#include "log.h"
#include "task.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *task_log(struct Task *t, char *verbed) {
    char *buf = malloc(200 * sizeof(char));
    sprintf(buf, "Task \"%s\" %s", t->name, verbed);
    return buf;
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
    LOGT(INFO, t->start, task_log(t, "started"));
}

/* Register the end time of a task */
void end_task(struct Task *t) {
    time(&t->end);
    LOGT(INFO, t->end, task_log(t, "ended"));
    t->finished = 1;
}

/* Run the task */
int run(struct Task *t) {
    start_task(t);
    t->failed = t->run();
    end_task(t);

    return t->failed;
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
