#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct {
    char name[40];
    int arrival_time;
    int service_time;
} Customer;

typedef struct Node {
    Customer data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *first_client;  // указатель первый элемент в очереди (выход из очереди)
    struct Node *last_client;   // указатель на последний элемент в очереди (вход в очередь)
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, Customer data);
Customer dequeue(Queue *q);
Customer show_first_elem(Queue *q);
Customer show_last_elem(Queue *q);
int list_is_empty(Queue *q);
void print_queue(Queue *q);
int get_queue_len(Queue *q);
void generate_queue(Queue *q);
void destroy_queue(Queue *q);

#endif