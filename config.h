#pragma once
#include "ini.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Config {
    int sleeptime;
};

int handler(void *user, const char *section, const char *name,
                   const char *value);
struct Config load_config();
