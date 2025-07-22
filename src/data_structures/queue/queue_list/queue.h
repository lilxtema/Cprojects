#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *first_elem;  // указатель первый элемент в очереди (выход из очереди)
    struct Node *last_elem;   // указатель на последний элемент в очереди (вход в очередь)
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int show_first_elem(Queue *q);
int list_is_empty(Queue *q);
void print_queue(Queue *q);
void destroy_queue(Queue *q);

#endif