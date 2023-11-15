#include <stdio.h>

void trocar(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *Lista, int baixo, int alto){
    int pivo = Lista[alto];
    int i = (baixo - 1);

    for(int j = baixo; j <= alto - 1; j++){
        if(Lista[j] < pivo){
            i++;
            trocar(&Lista[i], &Lista[j]);
        }
    }
    trocar(&Lista[i+1], &Lista[alto]);
    return (i+1);
}

void quicksort(int *Lista, int baixo, int alto){
    if(baixo < alto){
        int pi = particionar(Lista, baixo, alto);
        quicksort(Lista, baixo, pi - 1);
        quicksort(Lista, pi+1, alto);
    }
}

int BinarySearch(int Lista[], int tam, int elemento){
    int inicio = 0;
    int fim = tam - 1;

    while(inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;

        if(Lista[meio] == elemento){
            return meio;
        }

        if(Lista[meio] < elemento){
            inicio = meio + 1;
        }

        else{
            fim = meio - 1;
        }
    }

    return -1;
}

int main(void){
    int n, valor1, valor2, k, numPar = 0;

    scanf("%d %d", &n, &k);
    int lista[n];

    for(int x = 0; x < n; x++){
        scanf("%d", &lista[x]);
    }

    quicksort(lista, 0, n-1);

    for(int w = 0; w < n; w++){
        printf("%d ", lista[w]);
    }
    printf("\n");
    for(int y = 0; y < n; y++){
        valor1 = lista[y];
        valor2 = BinarySearch(lista, n, valor1+k);

        if(valor2 > -1){
            if(lista[valor2] - lista[y] == k){
                numPar++;
            }
        }         
    }

    printf("%d", numPar);
}