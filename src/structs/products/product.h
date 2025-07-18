#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_NAME_LENGTH 50
#define MAX_COUNTRY_LENGTH 30
#define MAX_COMPANY_LENGTH 40

typedef struct 
{
    char name[MAX_NAME_LENGTH]; 
    char country[MAX_COUNTRY_LENGTH]; 
    char company_name[MAX_COMPANY_LENGTH];
    int quantity; // оставшееся кол-во на складе
    double price; 

} Product;

// основной функционал
void bubble_sort(Product* products, int len);
void output_arr(Product* products, int len);
void find_products_by_company(Product* products, int len);

#endif