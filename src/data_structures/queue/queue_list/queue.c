#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void init_queue(Queue *q) {
    q->first_client = NULL;
    q->last_client = NULL;
}

void enqueue(Queue *q, int data) {
    Node *new_node = malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    // значит очередь пуста
    if (q->first_client == NULL) {
        q->first_client = q->last_client = new_node;
    } else {
        q->last_client->next =
            new_node;               // теперь указатель у бывшего последнего элемента указывает
                                    // на new_node вместо NULL, то есть он подвинулся
        q->last_client = new_node;  // перезаписываем, теперь новый последний элемент
    }
}

int dequeue(Queue *q) {
    if (q->first_client == NULL) {
        printf("Очередь пуста");
        return -1;
    }

    Node *temp = q->first_client;
    int value = temp->data;  // достаю первый в очереди элемент

    q->first_client = q->first_client->next;  // сдвигаю указатель на след элемент в списке

    if (q->first_client == NULL) {
        q->last_client = NULL;
    }

    free(temp);
    return value;
}

int show_first_elem(Queue *q) {
    if (q->first_client == NULL) {
        printf("Очередь пуста!");
        return -1;
    }

    return q->first_client->data;
}

int list_is_empty(Queue *q) { return q->first_client == NULL; }

void print_queue(Queue *q) {
    Node *current = q->first_client;
    printf("Очередь: ");

    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }

    printf("\n");
}
