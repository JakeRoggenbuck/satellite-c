#include <stdio.h>
#include <stdlib.h>
#pragma once

enum Severity { INFO, DEBUG, WARNING, ERROR, FATAL };

FILE *open_log(char *filepath);

void LOGT(enum Severity s, time_t t, char *msg);
void LOG(enum Severity s, char *msg);

char *severity_name(enum Severity s);
