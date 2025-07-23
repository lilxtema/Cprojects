#include "searcher.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *read_file() {
    char file_path[256];

    printf("Введите путь до файла: ");
    fgets(file_path, sizeof(file_path), stdin);
    file_path[strcspn(file_path, "\n")] = '\0';

    FILE *file = fopen(file_path, "r");

    return file;
}

void print_file(FILE *file) {
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((char)str[i]);
    }
}

void read_words(FILE *file, WordEntry *arr, int *len) {
    char word[100];
    int pos = 0;
    int c;
    int index_arr = 0;
    c = fgetc(file);
    while (c != EOF) {
        if (is_delimiter(c)) {
            if (pos > 0) {
                word[pos] = '\0';
                to_lowercase(word);
                int position = elem_in_array(arr, index_arr, word);
                if (position == -1) {
                    strcpy(arr[index_arr].word, word);
                    arr[index_arr].count = 1;
                    index_arr++;
                } else {
                    arr[position].count++;
                }
                pos = 0;
            }
        } else {
            if (pos < 100 - 1) {
                word[pos++] = c;
            }
        }

        c = fgetc(file);
    }

    if (pos > 0) {
        word[pos] = '\0';
        int position = elem_in_array(arr, index_arr, word);
        if (position == -1) {
            strcpy(arr[index_arr].word, word);
            arr[index_arr].count = 1;
            index_arr++;
        } else {
            arr[position].count++;
        }
    }

    *len = index_arr;
}

int is_delimiter(char c) { return isspace(c) || strchr(".,;:!?()\"'", c) != NULL || !isalpha(c); }

int elem_in_array(WordEntry *arr, int len, char *word) {
    int find_elem_index = -1;
    for (int i = 0; i < len; i++) {
        if (strcmp(arr[i].word, word) == 0) {
            find_elem_index = i;
        }
    }

    return find_elem_index;
}

void print_array(WordEntry *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("Слово: %s, Сколько раз встретилось: %d\n", arr[i].word, arr[i].count);
    }
}

void print_total_and_unique_words(WordEntry *arr, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += arr[i].count;
    }
    printf("\nПрочитано %d слов.\n", count);
    printf("Из них уникальных слов: %d\n\n", len);
}

void find_words(WordEntry *arr, int len) {
    char find_word[256];
    printf("Введите слово: ");
    scanf("%s", find_word);

    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(find_word, arr[i].word) == 0) {
            counter = arr[i].count;
            break;
        }
    }
    if (counter > 0) {
        printf("Слово '%s' встречается %d раз\n", find_word, counter);
    } else
        printf("Слово '%s' не встречается в файле!\n", find_word);
}

int starts_with(char *word, char *prefix) { return strncmp(word, prefix, strlen(prefix)) == 0; }

void find_for_prefix(WordEntry *arr, int len) {
    char prefix[20];
    printf("Введите префикс: ");
    scanf("%s", prefix);
    int counter = 0;

    printf("Слова, начинающиеся с '%s':\n", prefix);
    for (int i = 0; i < len; i++) {
        if (starts_with(arr[i].word, prefix)) {
            counter++;
            printf("%d. %s - в файле встретилось %d раз\n", counter, arr[i].word, arr[i].count);
        }
    }

    if (counter == 0) printf("Нет слов, начинающихся на этот префикс!\n");
}

void bubble_sort(WordEntry *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j].count < arr[j + 1].count) {
                WordEntry temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n\nОТСОРТИРОВАННЫЙ МАССИВ\n\n");
    for (int i = 0; i < len; i++) {
        printf("Слово: %s встречается: %d раз\n", arr[i].word, arr[i].count);
    }
}

void write_result(WordEntry *arr, int len) {
    FILE *result_file = fopen("result.txt", "w");
    if (result_file == NULL) {
        printf("Произошла ошибка при открытии и записи файла\n");
    } else {
        for (int i = 0; i < len; i++) {
            fprintf(result_file, "Слово: %s встречается: %d раз\n", arr[i].word, arr[i].count);
        }

        fclose(result_file);
    }
}