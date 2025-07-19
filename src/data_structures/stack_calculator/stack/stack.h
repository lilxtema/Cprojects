#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
    int data;
    struct tag_obj *next;
} stack;

void push(stack **top, int data);
int pop(stack **top);
void show_elements(stack *top);
int peek(stack *top);
int is_empty(stack *top);
