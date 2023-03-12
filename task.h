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
