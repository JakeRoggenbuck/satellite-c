#include "init_task.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Task *init = get_init_task();

    run(init);
    return 0;
}
