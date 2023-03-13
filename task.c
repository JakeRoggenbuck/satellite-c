#include "task.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
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
