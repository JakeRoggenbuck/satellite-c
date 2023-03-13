#include "log.h"
#include "task.h"
#include <stdio.h>

int run_init_task() {
    printf("Init!\n");
    open_log();
    return 0;
}

struct Task *get_init_task() {
    struct Task *t = build_task("init task");

    t->run = run_init_task;
    return t;
}
