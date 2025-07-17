#include <stdio.h>
#include <stdlib.h>
int read_row_col(int *row, int *col);
void init_matrix(int ***matrix, int row, int col);
int scan_matrix(int **matrix, int row, int col);
void clear_matrix(int ***matrix, int row, int col);
void degrees_90_matrix(int **matrix, int row, int col);
int **transponse_matrix(int **matrix, int row, int col);
void invert_arr(int *arr, int n);
void output(int **matrix, int row, int col);

int main() {
    int row, col;
    if (read_row_col(&row, &col)) {
        int **matrix;
        init_matrix(&matrix, row, col);
        if (scan_matrix(matrix, row, col)) {
            degrees_90_matrix(matrix, row, col);
            clear_matrix(&matrix, row, col);
        } else {
            printf("Ошибка при считывании матрицы");
            clear_matrix(&matrix, row, col);
        }
    } else {
        printf("Ошибка ввода");
    }

    return 0;
}

int read_row_col(int *row, int *col) {
    int flag = 1;
    printf("Введите кол-во строк и столбцов: ");
    if (scanf("%d %d", row, col) != 2 || getchar() == '.') {
        flag = 0;
    }

    return flag;
}

void init_matrix(int ***matrix, int row, int col) {
    *matrix = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++) {
        (*matrix)[i] = malloc(col * sizeof(int));
    }
}

int scan_matrix(int **matrix, int row, int col) {
    int flag = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d", &matrix[i][j]) != 1 || getchar() == '.') flag = 0;
        }
    }

    return flag;
}
void clear_matrix(int ***matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        free((*matrix)[i]);
    }

    free(*matrix);
}

void degrees_90_matrix(int **matrix, int row, int col) {
    int **result = transponse_matrix(matrix, row, col);
    for (int i = 0; i < col; i++) {
        invert_arr(result[i], row);
    }

    output(result, col, row);
    clear_matrix(&result, col, row);
}

int **transponse_matrix(int **matrix, int row, int col) {
    int **temp_matrix;
    init_matrix(&temp_matrix, col, row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp_matrix[j][i] = matrix[i][j];
        }
    }

    return temp_matrix;
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

void output(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col - 1) printf(" ");
        }
        if (i != row - 1) printf("\n");
    }
}