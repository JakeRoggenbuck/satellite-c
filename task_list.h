#pragma once
#include "task.h"

struct TaskList {
    struct Task **task_list;
    int index;
    int size;
};

void alloc_list(struct TaskList *l);

void add_list_chunk(struct TaskList *l);

struct TaskList *build_tasklist();

void add(struct TaskList *l, struct Task *t);
struct Task *pop(struct TaskList *l);
int empty(struct TaskList *l);
