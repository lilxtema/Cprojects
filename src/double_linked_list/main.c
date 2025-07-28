#include <stdio.h>
#include <stdlib.h>

#include "DoubleLinkedList/DoubleLinkedList.h"

void print_test_elements(int* array_nums, int len_arr);
void init_list(DoubleLinkedList* list, int* arr, int len);

int main() {
    int array_nums[] = {13, 5, 6, 80, 4, 3, 5, 7, 8};
    int len = sizeof(array_nums) / sizeof(int);
    DoubleLinkedList* list = create_list();
    print_test_elements(array_nums, len);
    init_list(list, array_nums, len);
    print_list(list);
    printf("\n");
    print_reverse_list(list);

    destroy_list(list);
    return 0;
}

void print_test_elements(int* array_nums, int len_arr) {
    printf("Добавляем в односвязный список элементы: ");
    for (int i = 0; i < len_arr; i++) {
        printf("%d", array_nums[i]);
        if (i != len_arr - 1)
            printf(" ");
        else
            printf(".\n");
    }
}

void init_list(DoubleLinkedList* list, int* arr, int len) {
    for (int i = 0; i < len; i++) {
        push_back(list, arr[i]);
    }
}