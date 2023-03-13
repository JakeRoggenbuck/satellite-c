#include "battery_check_task.h"
#include "cleanup_task.h"
#include "config.h"
#include "health_check_task.h"
#include "init_task.h"
#include "log.h"
#include "task.h"
#include "task_list.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIGTERM_MSG "SIGTERM received.\n"

struct TaskList *TASK_LIST;

void create_first_startup_tasks(struct TaskList *task_list) {
    struct Task *health_check = get_health_check_task();
    add(task_list, health_check);

    struct Task *init = get_init_task();
    add(task_list, init);
}

void create_cleanup_tasks(struct TaskList *task_list) {
    struct Task *cleanup = get_cleanup_task();
    add(task_list, cleanup);
}

void create_wake_up_tasks(struct TaskList *task_list) {
    add(task_list, get_battery_check_task());
}

void run_tasks(struct TaskList *task_list) {
    struct Task *current;
    while (!empty(task_list)) {
        current = pop(task_list);
        run(current);
    }
}

void sig_term_handler(int signum, siginfo_t *info, void *ptr) {
    write(STDERR_FILENO, SIGTERM_MSG, sizeof(SIGTERM_MSG));

    create_cleanup_tasks(TASK_LIST);
    run_tasks(TASK_LIST);

    exit(0);
}

void catch_sigterm() {
    static struct sigaction _sigact;

    memset(&_sigact, 0, sizeof(_sigact));
    _sigact.sa_sigaction = sig_term_handler;
    _sigact.sa_flags = SA_SIGINFO;

    sigaction(SIGINT, &_sigact, NULL);
}

int main() {
    struct Config config = load_config();

    TASK_LIST = build_tasklist();

    create_first_startup_tasks(TASK_LIST);
    run_tasks(TASK_LIST);

    catch_sigterm();

    while (1) {
        create_wake_up_tasks(TASK_LIST);
        run_tasks(TASK_LIST);

        LOG(INFO, "Sleeping...");
        sleep(config.sleeptime);
        LOG(INFO, "Woke up...");
    }

    return 0;
}
