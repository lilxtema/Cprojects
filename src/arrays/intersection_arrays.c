#include <stdio.h>
#include <stdlib.h>
int read_len(int *n);
int scan_arr(int *arr, int *n);
void output(int *arr, int size);
int num_in_arr(int num, int *arr, int len);
int *intersection_arrays(int *first_arr, int *second_arr, int first_len, int second_len,
                         int *result_size);

int main() {
    int first_len = 1, second_len = 1;
    int *first_arr = malloc(first_len * sizeof(int));
    int *second_arr = malloc(second_len * sizeof(int));
    if (scan_arr(first_arr, &first_len) && scan_arr(second_arr, &second_len)) {
        int result_size;
        int *result =
            intersection_arrays(first_arr, second_arr, first_len, second_len, &result_size);
        free(first_arr);
        free(second_arr);
        if (result != NULL) {
            printf("Пересечение массивов: ");
            output(result, result_size);
            free(result);
        } else {
            printf("Нет пересечений\n");
        }
    } else {
        printf("n/a");
        free(first_arr);
        free(second_arr);
    }
    return 0;
}

int read_len(int *n) {
    int flag = 1;
    if (scanf("%d", n) != 1 || getchar() == '.' || *n <= 0) {
        flag = 0;
    }

    return flag;
}

int scan_arr(int *arr, int *n) {
    int flag = 1;
    printf("Введите длину массива: ");
    if (read_len(n)) {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", &arr[i]) != 1 || getchar() == '.') flag = 0;
        }
    } else
        flag = 0;
    return flag;
}

void output(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(" ");
    }
}

int num_in_arr(int num, int *arr, int len) {
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == num) flag = 1;
    }

    return flag;
}

int *intersection_arrays(int *first_arr, int *second_arr, int first_len, int second_len,
                         int *result_size) {
    int count = 0;
    int *result_arr = NULL;
    for (int i = 0; i < first_len; i++) {
        if (num_in_arr(first_arr[i], second_arr, second_len)) count++;
    }

    if (count > 0) {
        result_arr = malloc(count * sizeof(int));
        int index = 0;
        for (int i = 0; i < first_len; i++) {
            if (num_in_arr(first_arr[i], second_arr, second_len) &&
                !num_in_arr(first_arr[i], result_arr, index))
                result_arr[index++] = first_arr[i];
        }

        *result_size = index;
    }

    return result_arr;
}