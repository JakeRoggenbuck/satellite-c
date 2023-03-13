#include "config.h"
#include "ini.h"
#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_NAME "config.ini"

int handler(void *user, const char *section, const char *name,
            const char *value) {
    struct Config *pconfig = (struct Config *)user;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("setup", "sleeptime")) {
        pconfig->sleeptime = atoi(value);
    } else if (MATCH("device", "batterypath")) {
        pconfig->batterypath = strdup(value);
    } else {
        return 0;
    }
    return 1;
}

struct Config load_config() {
    struct Config config;

    if (ini_parse(CONFIG_NAME, handler, &config) < 0) {
        char buf[200];
        sprintf(buf, "Can't load config file \"%s\"", CONFIG_NAME);
        LOG(FATAL, buf);
    }

    char buf[200];
    sprintf(buf, "Loaded config file \"%s\"", CONFIG_NAME);
    LOG(INFO, buf);

    return config;
}
