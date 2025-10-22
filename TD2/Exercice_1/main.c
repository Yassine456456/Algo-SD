#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int target=8000;
    int sizeofarr=10000;
    int array=malloc(sizeofarr*sizeof(int));
    for(int i=0;i<sizeofarr;i++){
        array[i]=i*2;
    }
    int lstart = clock();
    int l=linear_search(array,sizeofarr,target);
    int lend=clock();
    double ltime=(lend-lstart)/CLOCK_PER_SEC;
    printf("Algo lin a trouver la cible en %f secondes\n",ltime)
    if(is_sorted_nondecreasing(array,sizeofarr)){
        int jstart = clock();
        int j=jump_search(array,sizeofarr,target);
        int jend=clock();
        double jtime=(jend-jstart)/CLOCK_PER_SEC;
        printf("Algo jump a trouver la cible en %f secondes\n",jtime);
        int bstart = clock();
        int b=binary_search(array,sizeofarr,target);
        int bend=clock();
        double btime=(bend-bstart)/CLOCK_PER_SEC;
        printf("Algo binaire a trouver la cible en %f secondes\n",btime);
    }

    return 0;
}