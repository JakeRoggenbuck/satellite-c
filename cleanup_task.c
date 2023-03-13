#include "log.h"
#include "task.h"
#include <stdio.h>

int run_cleanup() {
	LOG(INFO, "Cleaning up...");
    close_log();
    return 0;
}

struct Task *get_cleanup_task() {
    struct Task *t = build_task("cleanup task");

    t->run = run_cleanup;
    return t;
}
