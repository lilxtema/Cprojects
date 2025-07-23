#ifndef SEARCH_H
#define SEARCH_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char word[256];
    int count;
} WordEntry;

FILE *read_file();
void print_file(FILE *file);
void to_lowercase(char *str);
void read_words(FILE *file, WordEntry *arr, int *len);
int is_delimiter(char c);
int elem_in_array(WordEntry *arr, int len, char *word);
void print_array(WordEntry *arr, int len);
void print_total_and_unique_words(WordEntry *arr, int len);
void find_words(WordEntry *arr, int len);
int starts_with(char *word, char *prefix);
void find_for_prefix(WordEntry *arr, int len);
void bubble_sort(WordEntry *arr, int len);
void write_result(WordEntry *arr, int len);
#endif