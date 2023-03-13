#pragma once
#include "config.h"
#include "task.h"
#include <stdio.h>

int run_battery_capacity(struct Config *c);

struct Task *get_battery_check_task();
