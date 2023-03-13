#pragma once
#include <time.h>

struct Task {
    char *name;
    time_t start;
    time_t end;

    int finished;
    int failed;

    int (*run)();
};

struct Task *build_task(char *name);

int run(struct Task *t);

void display(struct Task *t);

void start_task(struct Task *t);
void end_task(struct Task *t);

char *timestr(time_t ta);
