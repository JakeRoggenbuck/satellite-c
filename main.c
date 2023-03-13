#include "init_task.h"
#include "health_check_task.h"
#include "task.h"
#include "task_list.h"
#include <stdio.h>
#include <stdlib.h>

void create_tasks(struct TaskList *task_list) {
    struct Task *init = get_init_task();
    add(task_list, init);

    struct Task *health_check = get_health_check_task();
    add(task_list, health_check);
}

int main() {
    struct TaskList *task_list = build_tasklist();
    create_tasks(task_list);

    struct Task *current;
    while (!empty(task_list)) {
        current = pop(task_list);
        run(current);
    }

    return 0;
}
