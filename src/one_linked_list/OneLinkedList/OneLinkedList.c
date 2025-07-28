#include "OneLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

OneLinkdedList* create_list() {
    OneLinkdedList* new_list = malloc(sizeof(OneLinkdedList));
    new_list->head = NULL;
    new_list->size = 0;

    return new_list;
}

Node* create_node(int elem) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new_node->next = NULL;
    new_node->data = elem;

    return new_node;
}

void destroy_list(OneLinkdedList* list) {
    if (list == NULL) return;

    Node* current = list->head;

    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void push_front(OneLinkdedList* list, int elem)  // добавление в начало
{
    Node* new_node = create_node(elem);

    new_node->next = list->head;  // новый узел теперь ссылается на head списка -> new_node - новый
                                  // элем, next - ссылка на сдвинутый 1 элемент
    list->head = new_node;  // теперь список начинается с нового эл-та. Head указывает на это
    list->size++;
}

void push_back(OneLinkdedList* list, int elem)  // добавление в конец
{
    Node* new_node = create_node(elem);

    if (list->head == NULL)  // значит список пуст, создаем первый элем
    {
        list->head = new_node;
        // list->size++;
    } else {
        Node* current = list->head;

        while (current->next != NULL) current = current->next;

        current->next = new_node;  // вставляем новый элемент в конец списка
    }

    list->size++;  // в любом случае увеличиваем размер на 1
}

int pop_front(OneLinkdedList* list) {
    if (list->head == NULL) {
        printf("Список пуст!\n");
        return -99999;
    }
    Node* temp = list->head;
    int data = list->head->data;
    list->head = list->head->next;
    free(temp);
    list->size--;

    return data;
}

int pop_back(OneLinkdedList* list) {
    if (list->head == NULL) {
        printf("Список пуст!\n");
        return -99999;
    }

    int data;
    if (list->head->next == NULL)  // 1 элемент в списке
    {
        data = list->head->data;
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        data = current->next->data;
        free(current->next);
        current->next = NULL;
    }

    list->size--;  // в любом из исходов(кроме пустого списка) уменьшаем размер на единицу
    return data;
}

Node* get_At(OneLinkdedList* list, int k) {
    if (k < 0) return NULL;

    Node* current = list->head;
    int index = 0;
    while (current != NULL && index != k) {
        current = current->next;
        index++;
    }

    return (index == k) ? current : NULL;
}

void insert(OneLinkdedList* list, int k, int data) {
    Node* left = get_At(list, k);
    if (left == NULL || k < 0) {
        printf("некорректный индекс");
        return;
    }

    if (k == 0) {
        push_front(list, data);
        return;
    }
    Node* right = left->next;
    Node* new_node = create_node(data);

    left->next = new_node;
    new_node->next = right;
    list->size++;
}

void erase(OneLinkdedList* list, int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front(list);
        return;
    }

    Node* left = get_At(list, k - 1);
    Node* del_node = left->next;  // узел, который надо удалить

    if (del_node == NULL) return;  // удалять нечего, выходим из фун-ии

    Node* right = del_node->next;
    free(del_node);
    left->next = right;

    list->size--;
}

int len(OneLinkdedList* list) { return list->size; }

void print_list(OneLinkdedList* list) {
    Node* current = list->head;

    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" ");
    }
}

Node* split(Node* head) {
    Node* slow = head;        // двигается на один шаг вперед
    Node* fast = head->next;  // двигается на два шага вперед

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // шаг
        fast = fast->next->next;  // 2 шага
    }

    Node* start_position_second_half = slow->next;  // запомнил начало второй половины
    slow->next = NULL;                              // разрываем связ между половинами

    return start_position_second_half;
}

Node* merge(Node* a, Node* b) {
    Node temp_head;
    Node* tail = &temp_head;
    temp_head.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;  // добавляем узел из списка a
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a == NULL) ? b : a;
    return temp_head.next;  // возвращаю указатель на начало слитого списка
}

void merge_sort(Node** head) {
    Node* left_half = *head;
    if ((*head) == NULL || (*head)->next == NULL) {
        return;
    }

    Node* right_half = split(left_half);

    merge_sort(&left_half);
    merge_sort(&right_half);

    *head = merge(left_half, right_half);
}

void list_merge_sort(OneLinkdedList* list) {
    if (list == NULL || list->head == NULL) return;

    merge_sort(&(list->head));
    // list->size = 0;
    // Node* current = list->head;
    // int len = 0;
    // while (current != NULL)
    // {
    //     len++;
    //     current = current->next;
    // }
    // list->size = len;
}

Node* merge_two_lists(Node* a, Node* b) {
    Node* current = a;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = b;
    return a;
}

void reverse_list(OneLinkdedList* list) {
    if (list == NULL || list->head == NULL) return;

    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    list->head = prev;
}