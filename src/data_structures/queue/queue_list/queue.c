#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void init_queue(Queue *q) {
    q->first_elem = NULL;
    q->last_elem = NULL;
}

void enqueue(Queue *q, int data) {
    Node *new_node = malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    // значит очередь пуста
    if (q->first_elem == NULL) {
        q->first_elem = q->last_elem = new_node;
    } else {
        q->last_elem->next = new_node;  // теперь указатель у бывшего последнего элемента указывает
                                        // на new_node вместо NULL, то есть он подвинулся
        q->last_elem = new_node;        // перезаписываем, теперь новый последний элемент
    }
}

int dequeue(Queue *q) {
    if (q->first_elem == NULL) {
        printf("Очередь пуста");
        return -1;
    }

    Node *temp = q->first_elem;
    int value = temp->data;  // достаю первый в очереди элемент

    q->first_elem = q->first_elem->next;  // сдвигаю указатель на след элемент в списке

    if (q->first_elem == NULL) {
        q->last_elem = NULL;
    }

    free(temp);
    return value;
}

int show_first_elem(Queue *q) {
    if (q->first_elem == NULL) {
        printf("Очередь пуста!");
        return -1;
    }

    return q->first_elem->data;
}

int list_is_empty(Queue *q) { return q->first_elem == NULL; }

void print_queue(Queue *q) {
    Node *current = q->first_elem;
    printf("Очередь: ");

    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }

    printf("\n");
}

void destroy_queue(Queue *q) {
    while (q->first_elem != NULL) {
        Node *temp = q->first_elem;
        q->first_elem = q->first_elem->next;

        free(temp);
    }

    q->last_elem = NULL;
}