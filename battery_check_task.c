#include "config.h"
#include "log.h"
#include "task.h"
#include <stdio.h>

int run_battery_capacity() {
    return -1;
}

struct Task *get_battery_check_task() {
    struct Task *t = build_task("battery capacity task");

    t->run = run_battery_capacity;
    return t;
}
