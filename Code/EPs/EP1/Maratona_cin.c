#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int num;
}Pessoas;

void Merge(Pessoas *A, int l, int r){
    Pessoas temp[50000];

    for(int i = l; i <= r; i++){
        temp[i].num = A[i].num;
        strcpy(temp[i].nome, A[i].nome);
    }

    int m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;

    for(int curr = l; curr <= r; curr++){
        if(i1 == m+1){
            A[curr].num = temp[i2].num;
            strcpy(A[curr].nome, temp[i2].nome);
            i2++;
        }
        else if(i2 > r){
            A[curr].num = temp[i1].num;
            strcpy(A[curr].nome, temp[i1].nome);
            i1++;
        }
        else if(temp[i1].num <= temp[i2].num){
            A[curr].num = temp[i1].num;
            strcpy(A[curr].nome, temp[i1].nome);
            i1++;
        }
        else{
            A[curr].num = temp[i2].num;
            strcpy(A[curr].nome, temp[i2].nome);
            i2++;
        }
    }
}

void Mergesort(Pessoas *A, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        Mergesort(A, l, m);
        Mergesort(A, m+1, r);
        Merge(A, l, r);
    }
}
int main(void){
    int c;
    scanf("%d", &c); //Recebe a quantidade de concluintes
    Pessoas *concluintes = (Pessoas *)malloc(sizeof(Pessoas) * c); //Aloca no vetor dinâmico concluintes, a quantidade de concluintes

    if(concluintes){
        for(int x = 0; x < c; x++){
            scanf(" %[^ ]", concluintes[x].nome);
            scanf("%d", &concluintes[x].num);
        }
        Mergesort(concluintes, 0, c-1); //Depois de receber todos os concluintes, manda para a ordenação
    }
    else{
        printf("Erro na primeira alocação");
    }

    for(int y = 0; y < c; y++){
        printf("%s %d\n", concluintes[y].nome, concluintes[y].num);
    }

    return 0;
}