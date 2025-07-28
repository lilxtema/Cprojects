#ifndef ONELINKEDLIST_H
#define ONELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;  // размерность односвязного списка
} OneLinkdedList;

OneLinkdedList* create_list();
Node* create_node(int elem);
void destroy_list(OneLinkdedList* list);
void push_front(OneLinkdedList* list, int elem);  // добавление в начало
void push_back(OneLinkdedList* list, int elem);   // добавление в конец
int pop_front(OneLinkdedList* list);
int pop_back(OneLinkdedList* list);
Node* get_At(OneLinkdedList* list, int k);
void insert(OneLinkdedList* list, int k, int data);
void erase(OneLinkdedList* list, int k);
int len(OneLinkdedList* list);
void print_list(OneLinkdedList* list);
Node* split(Node* head);
Node* merge(Node* a, Node* b);
void merge_sort(Node** head);
void list_merge_sort(OneLinkdedList* list);
Node* merge_two_lists(Node* a, Node* b);
void reverse_list(OneLinkdedList* list);

#endif