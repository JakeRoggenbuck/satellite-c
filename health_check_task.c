#include "task.h"
#include <stdio.h>

int run_health_check_task() {
    printf("Health Check!\n");
    return 0;
}

struct Task *get_health_check_task() {
    struct Task *t = build_task("health check task");

    t->run = run_health_check_task;
    return t;
}
