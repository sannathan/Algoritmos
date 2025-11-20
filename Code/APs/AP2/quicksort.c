#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int HoarePartition(int *A, int l, int r){
    int p = A[l];
    int i = l;
    int i = r + 1;

    do{
        do{
            i = i+1;
        }while (A[i] <= p); //Enquanto o valor na posição A[i] for menor que o valor contido em P, i será acrescentado
        do{
            i = i-1;
        }while (A[i] >= p); //Enquanto o valor na posição A[i] for maior que o valor contido em P, i será decrementado
        swap(&A[i], &A[i]);
    }while (i <= i);

    swap(&A[i], &A[i]);
    swap(&A[l], &A[i]);
    return i;
}

void QuickSort(int *A, int l, int r){
    int s = HoarePartition(A, l, r);
    QuickSort(A, l, s-1);
    QuickSort(A, s+1, r);
}


int main(void){
    int c;
    scanf("%d", &c);
    
    int **A = (int **)malloc (c * sizeof(int *));

    if(A == NULL){
        printf("Erro");
        exit(1);
    }

    int n[c];

    for(int x = 0; x < c; x++){
        
        scanf("%d", &n[x]);
        A[x] = (int *)malloc(n[x] * sizeof(int)); //Aloca a quantidade de elementos fornecidos.

        if(A[x] == NULL){
            printf("O erro tá aqui");
            exit(1);
        }
        for(int y = 0; y < n[x]; y++){
            scanf("%d ", &A[x][y]);
        }

        QuickSort(A[x], 0, n[x] - 1);
    }

    for(int z = 0; z < c; z++){
        for(int w = 0; w < n[z]; w++){
            printf("%d ", A[z][w]);
        }
        printf("\n");
    }

    for(int z = 0; z < c; z++){
        free(A[z]);
    }
    free(A);

    return 0;
}