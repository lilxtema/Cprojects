#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_searcher/searcher.h"
void menu(FILE* file);

int main() {
    FILE* file = read_file();
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
    } else {
        menu(file);
        fclose(file);
    }

    return 0;
}

void menu(FILE* file) {
    WordEntry arr[256];
    int len;
    printf("\033[2J\033[H");
    printf("Считывание прошло успешно! Краткая информация:\n");
    read_words(file, arr, &len);
    print_total_and_unique_words(arr, len);
    printf("Нажмите пробел, чтобы продолжить\n");
    while (getchar() != ' ');
    int choice;
    int flag = 1;

    while (flag) {
        printf("\033[2J\033[H");  // очистка экрана
        printf("Выберите действие: \n");
        printf("1. Найти слово\n");
        printf("2. Найти по префиксу\n");
        printf("3. Сортировать по частоте\n");
        printf("4. Сохранить результат\n");
        printf("5. Выйти\n");

        scanf("%d", &choice);

        if (choice == 1) {
            find_words(arr, len);
            printf("Нажмите пробел, чтобы выйти в меню\n");
            while (getchar() != ' ');
        } else if (choice == 2) {
            find_for_prefix(arr, len);
            printf("Нажмите пробел, чтобы выйти в меню\n");
            while (getchar() != ' ');
        } else if (choice == 3) {
            bubble_sort(arr, len);
            printf("Нажмите пробел, чтобы выйти в меню\n");
            while (getchar() != ' ');
        }

        else if (choice == 4) {
            write_result(arr, len);
            printf("Нажмите пробел, чтобы выйти в меню\n");
            while (getchar() != ' ');
        } else if (choice == 5)
            flag = 0;
        else
            printf("Введены неверные данные!\n");
    }
}
