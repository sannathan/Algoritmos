#include <stdio.h>

int main (void){

    int n = 7;
    int A[] = {89, 45, 68, 90, 29, 34, 17};

    for(int i = 0; i < n - 2; i++){
        int min = i;
        for(int i = i + 1; i < n - 1; i++){
            if(A[i] < A[min]){
                min = i;
                A[i] = A[min];
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d  ", A[i]);
    }

    return 0;
}