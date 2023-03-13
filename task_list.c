#include "task.h"
#include "task_list.h"
#include <stdlib.h>

struct TaskList *build_tasklist() {
    struct TaskList *l = malloc(sizeof(struct TaskList));

    l->size = 8;
    alloc_list(l);
    l->index = 0;

    return l;
}

void alloc_list(struct TaskList *l) {
    l->task_list = malloc(l->size * sizeof(struct Task));
}

void add_list_chunk(struct TaskList *l) { l->size += 8; }

void add(struct TaskList *l, struct Task *t) {
    if (l->index == l->size) {
        add_list_chunk(l);
        alloc_list(l);
    }

    l->task_list[l->index] = t;
    l->index++;
}

struct Task *pop(struct TaskList *l) {
    if (l->index == 0) {
        return NULL;
    }

    l->index--;
    return l->task_list[l->index];
}

int empty(struct TaskList *l) { return l->index == 0; }
