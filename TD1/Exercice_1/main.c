#include <stdio.h>
#include <time.h>
#include "fibo.h"

int main(void) {
    int n=30;
    long long tableFib[n+1];
    clock_t start, end;

    start = clock();
    long long r = fibo(n);
    end = clock();
    double time_1=(double)(end-start)/CLOCKS_PER_SEC;

    
    for (int i = 0; i <= n; ++i) tableFib[i] = -1;
    tableFib[0] = 0; tableFib[1] = 1;

    start = clock();
    long long rd = fibo_dynamic(n, tableFib);
    end = clock();
    double time_2=(double)(end-start)/CLOCKS_PER_SEC;



    
    printf("fibo(%d) naif = %lld en %f secondes\n", n, r,time_1);
    printf("fibo(%d) dynamique = %lld en %f secondes\n", n, rd,time_2);
}