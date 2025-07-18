#include "product.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(Product* products, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            double i_total = products[j].price * products[j].quantity;
            double j_total = products[j + 1].price * products[j + 1].quantity;

            if (i_total < j_total) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            } else if (i_total == j_total && strcmp(products[j].name, products[j + 1].name) > 0) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void output_arr(Product* products, int len) {
    for (int i = 0; i < len; i++) {
        printf(
            "Название товара: %s, Страна производитель: %s, Остаток на складе: %d, Стоимость за "
            "ед.товара: %.2f, Совокупная стоимость %.2f\n",
            products[i].name, products[i].country, products[i].quantity, products[i].price,
            products[i].quantity * products[i].price);
    }
}

void find_products_by_company(Product* products, int len) {
    char company[40];
    printf("Введите название компании: ");
    scanf("%s", company);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(products[i].company_name, company) == 0) count++;
    }

    printf("Найдено %d продуктов от этой компании\n", count);

    for (int i = 0; i < len; i++) {
        if (strcmp(products[i].company_name, company) == 0)
            printf("Название: %s. Цена: %.2f. Остаток на складе: %d\n", products[i].name,
                   products[i].price, products[i].quantity);
    }
}

void country_count_products(Product* products, int len) {
    int unique_count = 0;
    int found = 0;
    Count_Unique_Country count_array[len];
    for (int i = 0; i < len; i++) {
        count_array[i].count_products_from_country = 0;
    }

    for (int i = 0; i < len; i++) {
        found = 0;
        for (int j = 0; j < len; j++) {
            if (strcmp(count_array[j].country_name, products[i].country) == 0) {
                count_array[j].count_products_from_country += products[i].quantity;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(count_array[unique_count].country_name, products[i].country);
            count_array[unique_count].count_products_from_country = products[i].quantity;
            unique_count++;
        }
    }

    for (int i = 0; i < unique_count; i++) {
        for (int j = 0; j < unique_count - 1; j++) {
            if (count_array[j + 1].count_products_from_country >
                count_array[j].count_products_from_country) {
                Count_Unique_Country temp = count_array[j];
                count_array[j] = count_array[j + 1];
                count_array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < unique_count; i++) {
        printf("%s: %d\n", count_array[i].country_name, count_array[i].count_products_from_country);
    }
}

void country_count_unique_products(Product* products, int len) {
    int unique_count = 0;
    int found = 0;
    Count_Unique_Country count_array[len];
    for (int i = 0; i < len; i++) {
        count_array[i].count_products_from_country = 0;
    }

    for (int i = 0; i < len; i++) {
        found = 0;
        for (int j = 0; j < len; j++) {
            if (strcmp(count_array[j].country_name, products[i].country) == 0) {
                count_array[j].count_products_from_country += 1;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(count_array[unique_count].country_name, products[i].country);
            count_array[unique_count].count_products_from_country = 1;
            unique_count++;
        }
    }

    for (int i = 0; i < unique_count; i++) {
        for (int j = 0; j < unique_count - 1; j++) {
            if (count_array[j + 1].count_products_from_country >
                count_array[j].count_products_from_country) {
                Count_Unique_Country temp = count_array[j];
                count_array[j] = count_array[j + 1];
                count_array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < unique_count; i++) {
        printf("%s: %d\n", count_array[i].country_name, count_array[i].count_products_from_country);
    }
}
