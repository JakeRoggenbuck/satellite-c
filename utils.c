#include <string.h>
#include <time.h>
#include <stdlib.h>

char *timestr(time_t ta) {
    struct tm *timea = localtime(&ta);
    char *buf = malloc(30 * sizeof(char));
    strftime(buf, 30, "%m-%d-%y %H:%M:%S", timea);
    return buf;
}
