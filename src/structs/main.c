#include <stdio.h>

#include "products/product.h"
#include "tests/test.h"

int main(int argc, char *argv[]) {
    Product products[] = {// Электроника
                          {"iPhone 15", "USA", "Apple", 15, 999.0},
                          {"Galaxy S23", "Korea", "Samsung", 12, 899.0},
                          {"MacBook Pro", "USA", "Apple", 8, 1999.0},
                          {"PlayStation 5", "Japan", "Sony", 6, 499.0},
                          {"Smart TV 55\"", "Korea", "LG", 10, 699.0},

                          // Компьютерные аксессуары
                          {"Wireless Mouse", "China", "Logitech", 25, 29.99},
                          {"Mechanical Keyboard", "Germany", "Cherry", 18, 129.0},
                          {"Bluetooth Headphones", "USA", "Bose", 14, 199.0},
                          {"USB-C Hub", "China", "Anker", 30, 35.5},

                          // Бытовая техника
                          {"Coffee Machine", "Italy", "DeLonghi", 7, 249.0},
                          {"Blender", "Germany", "Bosch", 12, 89.99},
                          {"Robot Vacuum", "China", "Xiaomi", 9, 299.0},

                          // Одежда и аксессуары
                          {"Running Shoes", "USA", "Nike", 22, 120.0},
                          {"Leather Wallet", "Italy", "Gucci", 5, 350.0},
                          {"Winter Jacket", "Canada", "Canada Goose", 4, 899.0},

                          // Для дома
                          {"Air Purifier", "Switzerland", "IQAir", 3, 899.0},
                          {"Smart Thermostat", "USA", "Nest", 15, 199.0},
                          {"LED Bulb", "Netherlands", "Philips", 50, 9.99},

                          // Разное
                          {"Yoga Mat", "USA", "Lululemon", 20, 68.0},
                          {"Water Bottle", "USA", "Hydro Flask", 35, 39.95},
                          {"Backpack", "Switzerland", "Victorinox", 18, 149.0}};

    int len = sizeof(products) / sizeof(products[0]);

    if (argc < 2) {
        // Если аргументов нет - запускаем все тесты
        run_tests(products, len);
    } else {
        // Запускаем конкретный тест
        run_single_test(products, len, argv[1]);
    }
    return 0;
}