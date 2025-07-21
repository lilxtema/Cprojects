#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "customer_queue/customer_queue.h"

int main() {
    srand(time(NULL));

    Queue customers_queue;
    init_queue(&customers_queue);
    generate_queue(&customers_queue);

    return 0;
}
