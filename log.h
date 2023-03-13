#include <stdio.h>
#include <stdlib.h>
#pragma once

enum Severity { INFO, DEBUG, WARNING, ERROR, FATAL };

void open_log();
void close_log();

void LOGT(enum Severity s, time_t t, char *msg);
void LOG(enum Severity s, char *msg);

char *severity_name(enum Severity s);
