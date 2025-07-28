#include "DoubleLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList* create_list() {
    DoubleLinkedList* new_list = malloc(sizeof(DoubleLinkedList));
    if (new_list == NULL) return NULL;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;

    return new_list;
}

Node* create_node(int elem) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new_node->data = elem;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void destroy_list(DoubleLinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;

    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void push_front(DoubleLinkedList* list, int elem) {
    Node* new_node = create_node(elem);

    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;  // теперь указатель prev первого элемента до прибавления
                                      // нового ссылается на новый
        list->head = new_node;
    }
    list->size++;
}

void push_back(DoubleLinkedList* list, int elem) {
    Node* new_node = create_node(elem);

    if (list->tail == NULL)
        list->head = list->tail = new_node;
    else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

int pop_front(DoubleLinkedList* list) {
    if (list->head == NULL) {
        printf("Список пуст!\n");
        return -99999;
    }

    Node* temp = list->head;
    int data = temp->data;

    list->head = list->head->next;

    if (list->head == NULL)  // список пуст
    {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }

    free(temp);
    list->size--;

    return data;
}

int pop_back(DoubleLinkedList* list) {
    if (list->tail == NULL) {
        printf("Список пуст!\n");
        return -99999;
    }

    Node* temp = list->tail;
    int data = temp->data;
    list->tail = list->tail->prev;

    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    free(temp);
    list->size--;
    return data;
}

Node* get_At(DoubleLinkedList* list, int k) {
    if (k < 0) return NULL;

    Node* current = list->head;
    int index = 0;

    while (current != NULL && index != k) {
        current = current->next;
    }

    return (index == k) ? current : NULL;
}

void insert(DoubleLinkedList* list, int k, int data) {
    if (k < 0) {
        printf("некорректный индекс");
        return;
    }

    Node* right = get_At(list, k);

    if (right == NULL) {
        push_back(list, data);
        return;
    }

    Node* left = right->prev;

    if (left == NULL) {
        push_front(list, data);
        return;
    }

    Node* new_node = create_node(data);
    new_node->next = right;
    new_node->prev = left;

    right->prev = new_node;
    left->next = new_node;
}

void erase(DoubleLinkedList* list, int k) {
    Node* temp_node = get_At(list, k);

    if (temp_node == NULL) {
        printf("Список пуст!");
        return;
    }

    if (temp_node->prev == NULL) {
        pop_front(list);
        return;
    }

    if (temp_node->next == NULL) {
        pop_back(list);
        return;
    }

    Node* left = temp_node->prev;
    Node* right = temp_node->next;

    left->next = right;
    right->prev = left;
}

int len(DoubleLinkedList* list) { return list->size; }

void print_list(DoubleLinkedList* list) {
    Node* current = list->head;
    printf("NULL <- ");

    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" <-> ");
    }

    printf(" -> NULL");
}

void print_reverse_list(DoubleLinkedList* list) {
    Node* current = list->tail;

    printf("NULL <- ");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->prev;
        if (current != NULL) printf(" <-> ");
    }

    printf(" -> NULL");
}