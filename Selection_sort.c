#include <stdio.h>

int main (void){

    int n = 7;
    int A[] = {89, 45, 68, 90, 29, 34, 17};

    for(int i = 0; i < n - 2; i++){
        int min = i;
        for(int j = i + 1; j < n - 1; j++){
            if(A[j] < A[min]){
                min = j;
                A[i] = A[min];
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d  ", A[i]);
    }

    return 0;
}