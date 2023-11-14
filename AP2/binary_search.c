#include <stdio.h>

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
    int n, m, v;
    scanf("%d", &n);
    int Lista[n];

    for(int x = 0; x < n; x++){
        scanf("%d", &Lista[x]);
    }

    scanf("%d", &m);
    int resultado[m];

    for(int y = 0; y < m; y++){
        scanf("%d", &v);

        resultado[y] = BinarySearch(Lista, n, v);
    }

    for(int z = 0; z < m; z++){
        if(resultado[z] == -1){
            printf("x\n");
        }
        else{
            printf("%d\n", resultado[z]);
        }
    }
    return 0;
}