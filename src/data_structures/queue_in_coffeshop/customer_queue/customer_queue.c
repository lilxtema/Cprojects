#include "customer_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue(Queue *q) {
    q->first_client = NULL;
    q->last_client = NULL;
}

void enqueue(Queue *q, Customer data) {
    Node *new_node = malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    // значит очередь пуста
    if (q->first_client == NULL) {
        q->first_client = q->last_client = new_node;
    } else {
        q->last_client->next =
            new_node;               // теперь указатель у бывшего последнего элемента указывает
                                    // на new_node вместо NULL, то есть он подвинулся
        q->last_client = new_node;  // перезаписываем, теперь новый последний элемент
    }
}

Customer dequeue(Queue *q) {
    if (q->first_client == NULL) {
        printf("Очередь пуста");
        exit(EXIT_FAILURE);
    }

    Node *temp = q->first_client;
    Customer value = temp->data;  // достаю первый в очереди элемент

    q->first_client = q->first_client->next;  // сдвигаю указатель на след элемент в списке

    if (q->first_client == NULL) {
        q->last_client = NULL;
    }

    free(temp);
    return value;
}

Customer show_first_elem(Queue *q) {
    if (q->first_client == NULL) {
        printf("Очередь пуста!\n");
        q->first_client->data.arrival_time = -1;
        q->first_client->data.service_time = -1;
    }

    return q->first_client->data;
}

Customer show_last_elem(Queue *q) {
    if (q->last_client == NULL) {
        printf("Очередь пуста!\n");
        q->last_client->data.arrival_time = -1;
        q->last_client->data.service_time = -1;
    }
    return q->last_client->data;
}

int list_is_empty(Queue *q) { return q->first_client == NULL; }

void print_queue(Queue *q) {
    Node *current = q->first_client;
    printf("\n\nОчередь:\n");

    while (current != NULL) {
        printf("%s пришел в %d мин, обслуживание занимает %d мин\n", current->data.name,
               current->data.arrival_time, current->data.service_time);
        if (current->next != NULL) printf("");
        current = current->next;
    }

    printf("\n\n");
}

int get_queue_len(Queue *q) {
    Node *current = q->first_client;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void generate_queue(Queue *q) {
    const char *first_names[] = {
        "Juan Too Many Tacos",   "Carlos Spicy Sombrero",   "Pablo Loco Nacho",
        "Diego Burrito Bandito", "Miguel Chili Con Crazy",  "Jose Jumping Jalapeño",
        "Maria Mucho Margarita", "Isabella Hot Tamale",     "Lupe Dancing Guacamole",
        "Ricardo Salsa Shaker",  "Fernando Fiesta Forever", "Rosa Spicy Señorita",
        "Carmen Cha-Cha Churro", "Elena Fiesta Fuego",      "Consuelo Crazy Cactus"};

    int max_queue = 10;
    int count_customers = 0, general_customers_count = 0;
    int casher_busy_time = 0, customers_left = 0;
    int serving = 0, count_served_clients = 0;
    int minute = 0;

    while (1) {
        printf("\033[2J\033[H");  // очистка экрана

        printf("Текущее время: %d минут\n", minute);
        printf("1. Продолжить симуляцию\n");
        printf("2. Просмотреть очередь\n");
        printf("3. Просмотреть конкретного клиента\n");
        printf("4. Выйти\n");
        printf("Выберите действие: ");

        char choice = getchar();

        if (choice == '1') {
            if (rand() % 100 < 50) {
                if (count_customers < max_queue) {
                    Customer new_client;
                    strcpy(new_client.name, first_names[rand() % 15]);

                    if (!list_is_empty(q)) {
                        // проверяю имена таким образом, что два подряд идущих имени не были
                        // одинаковыми
                        Customer last_client = show_last_elem(q);
                        if (new_client.name == last_client.name) {
                            strcpy(new_client.name, first_names[rand() % 15]);
                        }
                    }

                    new_client.arrival_time = minute;
                    new_client.service_time = rand() % 5 + 1;
                    enqueue(q, new_client);

                    count_customers++;
                    general_customers_count++;

                    printf("Новый клиент %s пришел в %d минут, обслуживание займет %d минут\n",
                           new_client.name, new_client.arrival_time, new_client.service_time);
                } else {
                    customers_left++;
                }
            }

            if (rand() % 100 < 10) print_queue(q);

            if (!serving && casher_busy_time == 0) {
                print_queue(q);
                if (!list_is_empty(q)) {
                    Customer first_client = dequeue(q);
                    casher_busy_time = first_client.service_time;
                    serving = 1;
                    count_customers--;
                }
            } else {
                casher_busy_time--;
                if (casher_busy_time == 0) {
                    count_served_clients++;
                    printf("%d-ый клиент обслужен!\n", count_served_clients);
                    serving = 0;
                }
            }
            minute++;
        }

        else if (choice == '2') {
            print_queue(q);
            printf("Нажмите клавишу пробел для продолжения...\n");
            while (getchar() != ' ');
        }

        else if (choice == '3') {
            int pos;
            printf("Введите позицию клиента (1 - %d): ", get_queue_len(q));

            if (scanf("%d", &pos) != 1 || pos < 1 || pos > get_queue_len(q)) {
                printf("Ошибка!\n");
            }

            Node *current = q->first_client;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }

            if (current != NULL)
                printf(
                    "Номер клиента в очереди %d: Имя: %s, Время захода: %d, Время на обслуживание: "
                    "%d\n",
                    pos, current->data.name, current->data.arrival_time,
                    current->data.service_time);
            printf("Нажмите пробел для продолжения...\n");
            while (getchar() != ' ');
        }

        else if (choice == '4') {
            printf("\n\nИтого:\n");
            printf("Обслужено клиентов: %d\n", count_served_clients);
            printf("Всего было клиентов: %d\n", general_customers_count);
            printf("Количество людей ушли из очереди: %d\n", customers_left);
            break;
        }
    }
}
