#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../products/product.h"

void test_sorting(Product *products, int len) {
    printf("\n\nТЕСТЫ СОРТИРОВКИ\n\n");
    printf("Отсортированные продукты по совокупной стоимости\n\n");
    bubble_sort(products, len);
    output_arr(products, len);
    printf("\n\n");
}

void test_search(Product *products, int len) {
    printf("\n\nТЕСТЫ ПОИСКА ПО НАЗВАНИЮ\n");
    printf("\n\n");
    find_products_by_company(products, len);
    printf("\n\n");
}

void run_tests(Product *products, int len) {
    test_sorting(products, len);
    test_search(products, len);
}

void run_single_test(Product *products, int len, const char *test_name) {
    if (strcmp(test_name, "sorting") == 0) {
        test_sorting(products, len);
    } else if (strcmp(test_name, "search") == 0) {
        test_search(products, len);
    } else {
        printf("Неизвестный тест %s\n", test_name);
    }
}