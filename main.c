#include "gettime.h"
#include <stdio.h>

int main() {
    char *timestr = time_string();

    printf("Satellite starting at: %s", timestr);
    return 0;
}
