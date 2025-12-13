#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct list {
    int inf;
    struct list* next;
};
void free_memory(struct list* F) {
    struct list* T;
    for (T = F;F != NULL;T = F) {
        F = F->next;
        free(T);
    }
}
void print_list(struct list* F) {
    struct list* T;
    for (T = F;T != NULL;T = T->next) {
        printf("%d ", T->inf);
    }
}
int main() {
    setlocale(0, "");
    struct list* F, * P, * T, * PU, * U, *T1, *prev, *T2;
    int a, x, t = 0;
    char ch;
    F = P = T = PU = U = T1 = prev = T2 = NULL;
    while (1) {
        printf("Добавить элемент (1-да, все остальное-нет) ");
        x = scanf("%d%c", &a, &ch);
        if (x != 2 || ch != '\n' || a != 1) {
            break;
        }
        T = (struct list*)malloc(sizeof(struct list));
        if (T == NULL) {
            printf("Ошибка выделения памяти");
            free_memory(F);
            return 0;
        }
        T->next = NULL;
        printf("Введите значение элемента ");
        x = scanf("%d%c", &T->inf, &ch);
        if (x != 2 || ch != '\n') {
            free(T);
            free_memory(F);
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
    printf("Исходный список\n");
    print_list(F);
    PU = F;
    while (PU->next != NULL) {
        U = PU->next;
        if (U->inf >= 0) {
            PU->next = U->next;
            free(U);
        }
        else {
            PU = U;
        }
    }
    if (F->inf >= 0) {
        T = F;
        F = F->next;
        free(T);
    }
    if (F == NULL) {
        printf("\nВ списке нет отрицательных элементов");
        return 0;
    }
    if (F->next != NULL) {
        P = NULL;
        while (t == 0) {
            t = 1;
            T = F;
            prev = NULL;
            while (T->next != P) {
                T1 = T->next;
                if (T->inf > T1->inf) {
                    t = 0;
                    T2 = T1->next;
                    T1->next = T;
                    T->next = T2;
                    if (prev == NULL) {
                        F = T1;
                        prev = F;
                    }
                    else {
                        prev->next = T1;
                        prev = T1;
                    }
                }
                else {
                    prev = T;
                    T = T->next;
                }
            }
        }
    }
    printf("\nПолучен список\n");
    print_list(F);
    free_memory(F);
    return 0;
}