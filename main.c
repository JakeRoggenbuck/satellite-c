#include "health_check_task.h"
#include "init_task.h"
#include "task.h"
#include "task_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SLEEP_TIME 10

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
    struct TaskList *task_list = build_tasklist();
    create_first_startup_tasks(task_list);
    run_tasks(task_list);

    while (1) {
        create_wake_up_tasks(task_list);
        run_tasks(task_list);

        printf("INFO: Sleeping...\n");
        sleep(SLEEP_TIME);
        printf("INFO: Woke up...\n");
    }
    return 0;
}
