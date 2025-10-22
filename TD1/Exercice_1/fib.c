#include "fib.h"

long long fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-2)+fib(n-1);
}


long long fib_dynamic(int n,long long * tableFib){
    if (n<=1){
        return n;
    }

    if (tableFib[n]!=-1){
        return tableFib[n];
    }
    else{
        tableFib[n]=fib_dynamic(n-1,tableFib)+fib_dynamic(n-2,tableFib);
        return tableFib[n];
    }
}