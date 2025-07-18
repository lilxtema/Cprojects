#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "product.h"

void bubble_sort(Product* products, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            double i_total = products[j].price * products[j].quantity; 
            double j_total = products[j + 1].price * products[j + 1].quantity; 

            if (i_total < j_total)
            {
                Product temp = products[j]; 
                products[j] = products[j + 1]; 
                products[j + 1] = temp;
            }
            else if (i_total == j_total && strcmp(products[j].name, products[j+1].name) > 0)
            {
                Product temp = products[j]; 
                products[j] = products[j+1]; 
                products[j+1] = temp;
            }
        }
    }
}

void output_arr(Product* products, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Название товара: %s, Страна производитель: %s, Остаток на складе: %d, Стоимость за ед.товара: %f\n", products[i].name, products[i].country, products[i].quantity, products[i].price);
    }
}

void find_products_by_company(Product* products, int len)
{
    char company[40];
    printf("Введите название компании: "); 
    scanf("%s", company); 
    int count = 0; 
    for (int i = 0; i < len; i++)
    {
        if (strcmp(products[i].company_name, company) == 0) count++;
    }

    printf("Найдено %d продуктов от этой компании\n", count); 

    for (int i = 0; i < len; i++)
    {
        if (strcmp(products[i].company_name, company) == 0) printf("Название: %s. Цена: %.2f. Остаток на складе: %d\n", products[i].name, products[i].price, products[i].quantity);
    }
}