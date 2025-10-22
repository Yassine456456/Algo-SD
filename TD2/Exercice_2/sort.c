#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap_int(&arr[i], &arr[min]);
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
}

static void merge(int *arr, int *tmp, int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= m) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int x = l; x <= r; x++) arr[x] = tmp[x];
}

static void merge_sort_rec(int *arr, int *tmp, int l, int r)
{
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_rec(arr, tmp, l, m);
    merge_sort_rec(arr, tmp, m + 1, r);
    merge(arr, tmp, l, m, r);
}

void merge_sort(int *arr, int n)
{
    if (!arr || n < 2) return;
    int *tmp = malloc(n * sizeof(int));
    if (!tmp) return;
    merge_sort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

static int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[r]);
    return i + 1;
}

static void quick_sort_rec(int *arr, int l, int r)
{
    if (l < r) {
        int p = partition(arr, l, r);
        quick_sort_rec(arr, l, p - 1);
        quick_sort_rec(arr, p + 1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n < 2) return;
    quick_sort_rec(arr, 0, n - 1);
}
