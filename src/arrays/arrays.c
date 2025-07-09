#include <stdio.h>
#include <stdlib.h>
int read_len(int *n);
int scan_arr(int *arr, int n);
int *delete_neg_num(int *arr, int n, int *new_size);
void output(int *arr, int size);
void bubble_sort(int *arr, int size);
void invert_arr(int *arr, int n);
double mean(int *arr, int n);
int median(int *arr, int n);

int main() {
    int n, new_size;
    if (read_len(&n)) {
        int *arr = malloc(n * sizeof(int));
        if (scan_arr(arr, n)) {
            int *result_arr = delete_neg_num(arr, n, &new_size);
            free(arr);
            bubble_sort(result_arr, new_size);
            printf("Отсортированный массив без отрицательных чисел: ");
            output(result_arr, new_size);

            printf("\n\n");

            printf("Инвертированный массив: ");
            invert_arr(result_arr, new_size);
            output(result_arr, new_size);

            printf("\n\n");

            printf("Медиана: ");
            int result = median(result_arr, n);
            printf("%d", result);
            free(result_arr);
        } else {
            free(arr);
            printf("n/a");
        }
    }

    else {
        printf("n/a");
    }
    return 0;
}

int read_len(int *n) {
    int flag = 1;
    printf("Введите длину: ");
    if (scanf("%d", n) != 1 || getchar() == '.' || *n <= 0) {
        flag = 0;
    }

    return flag;
}

int scan_arr(int *arr, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1 || getchar() == '.') flag = 0;
    }

    return flag;
}

int *delete_neg_num(int *arr, int n, int *new_size) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) count++;
    }

    int *result_arr = malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) result_arr[index++] = arr[i];
    }

    *new_size = count;
    return result_arr;
}

void output(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(" ");
    }
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void invert_arr(int *arr, int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

double mean(int *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;
}

int median(int *arr, int n) {
    bubble_sort(arr, n);
    if (n % 2 != 0)
        return arr[n / 2];
    else
        return arr[n / 2 - 1];
}