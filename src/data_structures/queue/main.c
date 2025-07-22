#include <stdio.h>
#include <stdlib.h>

#include "queue_list/queue.h"

int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);  // Очередь: 10 20 30

    printf("Удалён: %d\n", dequeue(&q));          // 10
    printf("Первый: %d\n", show_first_elem(&q));  // 20

    print_queue(&q);  // Очередь: 20 30

    destroy_queue(&q);
    return 0;
}