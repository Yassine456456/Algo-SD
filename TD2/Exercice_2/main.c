#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int max = 100;
    int size = 10;
    int *arr = malloc(size * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max;
    }

    printf("Tableau initial : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t s1 = clock();
    selection_sort(arr, size);
    clock_t s2 = clock();
    double t_sel = (double)(s2 - s1) / CLOCKS_PER_SEC;
    printf("Tri par sélection : %.6f s\n", t_sel);

    clock_t i1 = clock();
    insertion_sort(arr, size);
    clock_t i2 = clock();
    double t_ins = (double)(i2 - i1) / CLOCKS_PER_SEC;
    printf("Tri par insertion : %.6f s\n", t_ins);

    clock_t b1 = clock();
    bubble_sort(arr, size);
    clock_t b2 = clock();
    double t_bub = (double)(b2 - b1) / CLOCKS_PER_SEC;
    printf("Tri à bulles : %.6f s\n", t_bub);

    clock_t m1 = clock();
    merge_sort(arr, size);
    clock_t m2 = clock();
    double t_mer = (double)(m2 - m1) / CLOCKS_PER_SEC;
    printf("Tri fusion : %.6f s\n", t_mer);

    clock_t q1 = clock();
    quick_sort(arr, size);
    clock_t q2 = clock();
    double t_quick = (double)(q2 - q1) / CLOCKS_PER_SEC;
    printf("Tri rapide : %.6f s\n", t_quick);

    free(arr);
    return 0;
}
