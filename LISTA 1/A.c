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
int main(void){
    int n, m, valor = 0; 
    scanf("%d", &n); //Quantidade de barras de chocolate

    int custo[n];

    for(int x = 0; x < n; x++){
        scanf("%d", &custo[x]); //Preço das barras de chocolates
    }

    quicksort(&custo, 0, n - 1);


    scanf("%d", &m); //Quantidade de cupons
    int qtdBarras[m];


    for(int y = 0; y < m; y++){
        scanf("%d", &qtdBarras[y]); //Quantidade de barras necessárias para que o último seja de graça     
    }

    for(int z = 0; z < n; z++){
        valor += custo[z];
    }

    for(int y = 0; y < m; y++){
        printf("%d\n", valor - custo[n - qtdBarras[y]]);
    }

    return 0;
}
