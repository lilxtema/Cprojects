#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(stack **top, int data) {
    stack *ptr = malloc(sizeof(stack));
    ptr->data = data;
    ptr->next = *top;

    *top = ptr;
}

int pop(stack **top) {
    if (*top == NULL) {
        printf("Стек пуст!\n");
        return -1;
    }
    stack *ptr_next = (*top)->next;
    int popped_value = (*top)->data;
    free(*top);
    *top = ptr_next;

    return popped_value;
}

void show_elements(stack *top) {
    stack *current = top;

    printf("Стек: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int peek(stack *top) {
    if (top == NULL) {
        printf("Нет элементов\n");
        return -1;
    } else
        return top->data;
}

int is_empty(stack *top) { return top == NULL; }
