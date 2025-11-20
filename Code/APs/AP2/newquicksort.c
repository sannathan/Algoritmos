#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *arr, int baixo, int alto){
    int pivo = arr[alto];
    int i = (baixo - 1);

    for(int i = baixo; i <= alto - 1; i++){
        if(arr[i] < pivo){
            i++;
            trocar(&arr[i], &arr[i]);
        }
    }
    trocar(&arr[i+1], &arr[alto]);
    return (i+1);
}

void quicksort(int *arr, int baixo, int alto){
    if(baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}
int main(void){
    int c;
    int **vetor;
    scanf("%d", &c);
    int n[c];
    vetor = (int **)malloc(c * sizeof(int *));

    if(vetor){
        for(int x = 0; x < c; x++){
            scanf("%d", &n[x]);

            vetor[x] = (int *)malloc(n[x] * sizeof(int));

            if(vetor[x]){
                for(int y = 0; y < n[x]; y++){
                    scanf("%d", &vetor[x][y]);
                }

                quicksort(vetor[x], 0, n[x] - 1);
            }
            else{
                printf("Erro na segunda alocação");
                exit(1);
            }
        }
    }
    else{
        printf("Erro na primeira alocação");
        exit(1);
    }

    for(int x = 0; x < c; x++){
        for(int y = 0; y < n[x]; y++){
            printf("%d ", vetor[x][y]);
        }
        printf("\n");
    }

    return 0;
}