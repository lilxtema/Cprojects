#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../OneLinkedList/OneLinkedList.h"

void run_single_test(const char* test_name) {
    if (strcmp(test_name, "push_back_front") == 0) {
        test_init_and_push_front();
    } else if (strcmp(test_name, "insert_erase") == 0) {
        test_insert_erase();
    } else if (strcmp(test_name, "sort") == 0) {
        sort_test();
    } else if (strcmp(test_name, "merge") == 0) {
        merge_test();
    } else if (strcmp(test_name, "reverse") == 0) {
        reverse_test();
    } else {
        printf("Неизвестный тест %s\n", test_name);
    }
}

void test_init_and_push_front() {
    printf("ЗАПУСК ТЕСТОВ НА PUSH_BACK И POP_BACK\n-------------------------------------\n");
    OneLinkdedList* list1 = create_list();
    OneLinkdedList* list2 = create_list();
    if (list1 == NULL || list2 == NULL) {
        printf("Ошибка выделения памяти для односвязного списка\n");
    } else {
        int array_nums[] = {1, 23, 5, 6, 10, 23, 4, 5};
        int len_arr = sizeof(array_nums) / sizeof(int);
        print_test_elements(array_nums, len_arr);
        printf("\n");
        printf("ПЕРВЫЙ СПИСОК:\n");
        update_push_back_list(list1, array_nums, len_arr);
        printf("\n\n");
        printf("ВТОРОЙ СПИСОК:\n");
        update_push_front_list(list2, array_nums, len_arr);
        destroy_list(list1);
        destroy_list(list2);
    }
    printf("\n\nКОНЕЦ ТЕСТОВ\n-------------------------------------\n");
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

void init_list(OneLinkdedList* list, int* arr, int len) {
    for (int i = 0; i < len; i++) {
        push_back(list, arr[i]);
    }
}

void update_push_back_list(OneLinkdedList* list, int* array_nums, int len_arr) {
    init_list(list, array_nums, len_arr);

    printf("Итоговый односвязный список из элементов, добавленных с помощью push_back: ");
    print_list(list);
    printf("\n");
    printf("Тестирование удаления элементов из списка с помощью pop_back и pop_front\n");
    printf("Удален элемент %d с помощью pop_back. Измененный список: ", pop_back(list));
    print_list(list);
    printf("\n");
    printf("Удален элемент %d с помощью pop_front. Измененный список: ", pop_front(list));
    print_list(list);
    printf("\n");
}

void update_push_front_list(OneLinkdedList* list, int* array_nums, int len_arr) {
    init_list(list, array_nums, len_arr);

    printf("Итоговый односвязный список из элементов, добавленных с помощью push_front: ");
    print_list(list);
    printf("\n");
    printf("Тестирование удаления элементов из списка с помощью pop_back и pop_front\n");
    printf("Удален элемент %d с помощью pop_back. Измененный список: ", pop_back(list));
    print_list(list);
    printf("\n");
    printf("Удален элемент %d с помощью pop_front. Измененный список: ", pop_front(list));
    print_list(list);
    printf("\n");
}

void test_insert_erase() {
    printf("ЗАПУСК ТЕСТОВ НА INSERT и ERASE\n-------------------------------------\n");
    OneLinkdedList* list = create_list();
    if (list == NULL) {
        printf("Ошибка выделения памяти для односвязного списка\n");
    } else {
        int array_nums[] = {1, 23, 5, 6, 10, 23, 4, 5};
        int len_arr = sizeof(array_nums) / sizeof(int);
        print_test_elements(array_nums, len_arr);

        init_list(list, array_nums, len_arr);

        printf("Исходный список: ");
        print_list(list);
        int erase_index = rand() % len(list);
        printf("\nТест erase: удаляем элемент по индексу: %d\n", erase_index);
        erase(list, erase_index);
        printf("Итог: ");
        print_list(list);

        printf("\n");

        int insert_index = abs(rand() % len(list)), insert_elem = rand() % 10000;
        printf("\nТест insert: вставляем элемент %d по индексу: %d\n", insert_elem, insert_index);
        insert(list, insert_index, insert_elem);
        print_list(list);
        destroy_list(list);
    }
    printf("\n\nКОНЕЦ ТЕСТОВ\n-------------------------------------\n");
}

void sort_test() {
    printf("ЗАПУСК ТЕСТОВ НА СОРТИРОВКУ СЛИЯНИЕМ\n-------------------------------------\n");
    OneLinkdedList* list = create_list();
    if (list == NULL) {
        printf("Ошибка выделения памяти для односвязного списка\n");
    } else {
        int array_nums[] = {1, 23, 5, 6, 10, 23, 4, 5};
        int len_arr = sizeof(array_nums) / sizeof(int);
        print_test_elements(array_nums, len_arr);
        init_list(list, array_nums, len_arr);

        printf("Изначальный список: ");
        print_list(list);
        printf("\n");
        list_merge_sort(list);
        printf("Отсортированный список: ");
        print_list(list);
        destroy_list(list);
    }
    printf("\n\nКОНЕЦ ТЕСТОВ\n-------------------------------------\n");
}

void merge_test() {
    printf("ЗАПУСК ТЕСТОВ СЛИЯНИЕ ДВУХ СПИСКОВ\n-------------------------------------\n");
    OneLinkdedList* list1 = create_list();
    OneLinkdedList* list2 = create_list();
    if (list1 == NULL || list2 == NULL) {
        printf("Ошибка выделения памяти для односвязного списка\n");
    } else {
        int array_nums1[] = {1, 23, 5, 6, 10, 23, 4, 5};
        int array_nums2[] = {334, 2223, 44, 567, 43, 2};
        int len_arr1 = sizeof(array_nums1) / sizeof(int);
        int len_arr2 = sizeof(array_nums2) / sizeof(int);
        print_test_elements(array_nums1, len_arr1);
        print_test_elements(array_nums2, len_arr2);

        init_list(list1, array_nums1, len_arr1);
        init_list(list2, array_nums2, len_arr2);

        printf("Изначальный первый список: ");
        print_list(list1);
        printf("\n");
        printf("Изначальный второй список: ");
        print_list(list2);
        printf("\n");
        // Node* result = merge_two_lists(list1->head, list2->head);
        printf("\n");
        printf("Слитые 2 списка в один: ");
        print_list(list1);
        destroy_list(list1);
        destroy_list(list2);
    }
    printf("\n\nКОНЕЦ ТЕСТОВ\n-------------------------------------\n");
}

void reverse_test() {
    printf("ЗАПУСК ТЕСТОВ НА РЕВЕРС СПИСКА\n-------------------------------------\n");
    OneLinkdedList* list1 = create_list();
    if (list1 == NULL) {
        printf("Ошибка выделения памяти для односвязного списка\n");
    } else {
        int array_nums1[] = {1, 23, 5, 6, 10, 23, 4, 5};
        int len_arr1 = sizeof(array_nums1) / sizeof(int);
        print_test_elements(array_nums1, len_arr1);
        init_list(list1, array_nums1, len_arr1);

        reverse_list(list1);
        printf("Реверс списка: ");
        print_list(list1);
        destroy_list(list1);
    }
    printf("\n\nКОНЕЦ ТЕСТОВ\n-------------------------------------\n");
}
