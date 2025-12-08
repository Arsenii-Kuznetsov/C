#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct list {
    int inf;
    struct list* next;
};
int main() {
    setlocale(0, "");
    struct list* F, * P, * T, * F1, * P1, * T1, * prev, * T2;
    int a, x, t = 0;
    char ch;
    F = P = T = F1 = P1 = T1 = prev = T2 = NULL;
    while (1) {
        printf("Добавить элемент (1-да, все остальное-нет) ");
        x = scanf("%d", &a);
        ch = getchar();
        if (x == 0 || ch != '\n' || a != 1) {
            break;
        }
        T = (struct list*)malloc(sizeof(struct list));
        T->next = NULL;
        printf("Введите значение элемента ");
        x = scanf("%d", &T->inf);
        ch = getchar();
        if (x == 0 || ch != '\n') {
            free(T);
            printf("Введено некорректное значение элемента\n");
            return 0;
        }
        if (F == NULL) {
            F = T;
            P = T;
        }
        else {
            P->next = T;
            P = T;
        }
    }
    if (F == NULL) {
        printf("Введён пустой список");
        return 0;
    }
    for (T = F; T != NULL; T = T->next) {
        if (T->inf >= 0)
            continue;
        T1 = (struct list*)malloc(sizeof(struct list));
        T1->next = NULL;
        T1->inf = T->inf;
        if (F1 == NULL) {
            F1 = T1;
            P1 = T1;
        }
        else {
            P1->next = T1;
            P1 = T1;
        }
    }
    if (F1 == NULL) {
        printf("В списке нет отрицательных элементов");
        return 0;
    }
    P1 = NULL;
    while (t == 0) {
        t = 1;
        T1 = F1;
        while (T1->next != P1) {
            T2 = T1->next;
            if (T1->inf > T2->inf) {
                t = 0;
                if (prev == NULL) {
                    F1 = T2;
                }
                else {
                    prev->next = T2;
                }
                T1->next = T2->next;
                T2->next = T1;
                prev = T2;
            }
            else {
                prev = T1;
                T1 = T1->next;
            }
        }
        P1 = T1;
    }
    printf("Отсортированный список отрицательных элементов: ");
    for (T1 = F1; T1 != NULL; T1 = T1->next) {
        printf("%d ", T1->inf);
    }
    for (T1 = F1; F1 != NULL; T1 = F1) {
        F1 = F1->next;
        free(T1);
    }
    for (T = F; F != NULL; T = F) {
        F = F->next;
        free(T);
    }
    return 0;
}