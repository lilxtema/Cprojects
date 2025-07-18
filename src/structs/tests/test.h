#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../products/product.h"

void test_sorting(Product *products, int len);
void test_search(Product *products, int len);
void run_tests(Product *products, int len);
void run_single_test(Product *products,int len, const char* test_name);
