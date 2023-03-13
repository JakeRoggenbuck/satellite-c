#include "task.h"
#include "task_list.h"
#include <stdlib.h>

/* Build the task list and alloc the first chunk for the internal array */
struct TaskList *build_tasklist() {
    struct TaskList *l = malloc(sizeof(struct TaskList));

    l->size = 8;
    alloc_list(l);
    l->index = 0;

    return l;
}

/* Allocate the internal array with the size */
void alloc_list(struct TaskList *l) {
    l->task_list = malloc(l->size * sizeof(struct Task));
}

/* Add 8 to the size so that the alloc_list do so in chunks */
void add_list_chunk(struct TaskList *l) { l->size += 8; }

/* Add a task to the end of the internal array */
void add(struct TaskList *l, struct Task *t) {
    if (l->index == l->size) {
        add_list_chunk(l);
        alloc_list(l);
    }

    l->task_list[l->index] = t;
    l->index++;
}

/* Get a task from the end of the internal array */
struct Task *pop(struct TaskList *l) {
    if (l->index == 0) {
        return NULL;
    }

    l->index--;
    return l->task_list[l->index];
}

int empty(struct TaskList *l) { return l->index == 0; }
