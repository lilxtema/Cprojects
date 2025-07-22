#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack/stack.h"

int main() {
    stack *value = NULL;
    stack *history_operation_on_values = NULL;
    char command[5];

    int current = 0;
    push(&value, current);

    while (1) {
        printf("Введите команду (+, -, *, /, undo, exit): ");
        scanf("%s", command);

        if (strcmp(command, "undo") == 0) {
            if (history_operation_on_values == NULL)
                printf("Нечего отменять\n");
            else {
                current = pop(&history_operation_on_values);
                pop(&value);
                push(&value, current);
                printf("\n\nДанные восстановлены на шаг назад: %d\n", current);
            }
        } else if (strcmp(command, "exit") == 0)
            break;
        else {
            int num = 0;
            printf("Введите число: ");
            scanf("%d", &num);

            current = peek(value);
            push(&history_operation_on_values, current);  // обновляю историю

            if (strcmp(command, "+") == 0)
                current += num;
            else if (strcmp(command, "-") == 0)
                current -= num;
            else if (strcmp(command, "*") == 0)
                current *= num;
            else if (strcmp(command, "/") == 0)
                current /= num;
            else {
                printf("Введена неверная команда\n");
                continue;
            }

            push(&value, current);
            printf("Результат арифметической операции: %d\n", current);
        }
    }

    destroy_stack(&value);
    destroy_stack(&history_operation_on_values);
    return 0;
}