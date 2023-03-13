#include "config.h"
#include "health_check_task.h"
#include "init_task.h"
#include "log.h"
#include "task.h"
#include "task_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_first_startup_tasks(struct TaskList *task_list) {
    struct Task *init = get_init_task();
    add(task_list, init);

    struct Task *health_check = get_health_check_task();
    add(task_list, health_check);
}

void create_wake_up_tasks(struct TaskList *task_list) {
    struct Task *init = get_init_task();
    add(task_list, init);
}

void run_tasks(struct TaskList *task_list) {
    struct Task *current;
    while (!empty(task_list)) {
        current = pop(task_list);
        run(current);
    }
}

int main() {
    struct Config config = load_config();

    struct TaskList *task_list = build_tasklist();
    create_first_startup_tasks(task_list);
    run_tasks(task_list);

    while (1) {
        LOG(INFO, "Sleeping...");
        sleep(config.sleeptime);
        LOG(INFO, "Woke up...");
    }
    return 0;
}
