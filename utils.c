#include <string.h>
#include <time.h>

char *timestr(time_t ta) {
    struct tm *timea = localtime(&ta);
    char *timea_str = asctime(timea);

    char *p = strchr(timea_str, '\n');
    if (p != NULL) {
        *p = '\0';
    }

    return timea_str;
}
