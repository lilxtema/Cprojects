#ifndef TESTS_H
#define TESTS_H
#include <stdio.h>
#include <stdlib.h>

#include "../OneLinkedList/OneLinkedList.h"

void test_init_and_push_front();
void print_test_elements(int* array_nums, int len_arr);
void init_list(OneLinkdedList* list, int* arr, int len);
void update_push_back_list(OneLinkdedList* list, int* array_nums, int len_arr);
void update_push_front_list(OneLinkdedList* list, int* array_nums, int len_arr);
void test_insert_erase();
void sort_test();
void merge_test();
void run_single_test(const char* test_name);
void reverse_test();

#endif