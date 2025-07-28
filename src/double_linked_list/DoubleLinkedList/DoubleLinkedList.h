#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoubleLinkedList;

DoubleLinkedList* create_list();
Node* create_node(int elem);
void destroy_list(DoubleLinkedList* list);
void push_front(DoubleLinkedList* list, int elem);
void push_back(DoubleLinkedList* list, int elem);
int pop_front(DoubleLinkedList* list);
int pop_back(DoubleLinkedList* list);
Node* get_At(DoubleLinkedList* list, int k);
void insert(DoubleLinkedList* list, int k, int data);
void erase(DoubleLinkedList* list, int k);
int len(DoubleLinkedList* list);
void print_list(DoubleLinkedList* list);
void print_reverse_list(DoubleLinkedList* list);

#endif