#include <stdio.h>
#include <stdlib.h>

void merge(int *A,int l,int r){
    int temp[50000];
    for(int i = l; i <= r; i++){ // i = 0; i <= 1; i++
        temp[i] = A[i]; // temp[0] = A[0] && temp[1] = A[1]
    }
    int m = (l+r)/2; // m = 0
    int i1 = l; // i1 = 0
    int i2 = m+1; // i2 = 1

    for(int curr = l; curr <= r; curr++){ // curr = 0; curr <= 1
        if(i1 == m+1){ 
            A[curr] = temp[i2++]; //Se i1 == 1, A[0] = temp[1] e i1 incrementa 1, passando a valer 1
        }
        else if(i2 > r){
            A[curr] = temp[i1++]; //Se i2 > 1; A[0] = temp[0], e i1 incrementa 1, passando a valer 1
        }
        else if(temp[i1] <= temp[i2]){
            A[curr] = temp[i1++]; //Se temp[i1] <= temp[i2]; A[0] = temp[0] e i1 incrementa 1, passando a valer 1
        }
        else{
            A[curr] = temp[i2++]; //Caso contrário, A[0] = temp[1] e i2 incrementa 1, passando a valer 2;
        }
    }
}
void mergeSort(int *A,int l,int r){
    if(l < r){ //Quando l e r são os mesmos, ou seia, as listas estão todas unitárias, começa a ordenação
        int m = (l + r)/2; //Faz a divisão da lista em uma menor
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, r);
    }
}

int main(void){
    int c;
    scanf("%d", &c);
    int n[c];
    int **A = (int **)malloc (c * sizeof(int *));

    if(A == NULL){
        printf("Erro");
        exit(1);
    }


    for(int x = 0; x < c; x++){
        scanf("%d", &n[x]);
        A[x] = (int *)malloc(n[x] * sizeof(int)); //Aloca a quantidade de elementos fornecidos.

        if(A[x] == NULL){
            printf("O erro tá aqui");
            exit(1);
        }
        for(int y = 0; y < n[x]; y++){
            scanf("%d", &A[x][y]);
        }

        mergeSort(A[x], 0, n[x] - 1);
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