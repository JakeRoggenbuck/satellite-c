#pragma once
#include "log.h"
#include "task.h"
#include <stdio.h>

int run_cleanup();

struct Task *get_cleanup_task();
