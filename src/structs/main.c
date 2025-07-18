#include <stdio.h>
#include "products/product.h"
#include "tests/test.h"

int main(int argc, char *argv[]) {
    
    Product products[] = {
    {"Laptop", "USA", "Apple", 5, 800.0},
    {"Mouse", "USA", "Apple", 20, 25.0},
    {"Keyboard", "Korea", "Samsung", 10, 50.0}
    };  

    int len = sizeof(products)/sizeof(products[0]);

    if (argc < 2) {
        // Если аргументов нет - запускаем все тесты
        run_tests(products, len);
    } else {
        // Запускаем конкретный тест
        run_single_test(products, len, argv[1]);
    }
    return 0;
}