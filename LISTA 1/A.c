#include <stdio.h>

void trocar(long long int *a, long long int*b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int particionar(long long int *Lista, int baixo, int alto){
    long long int pivo = Lista[baixo];
    int i = baixo;
    int i = alto+1;

    do{
        do{
            i = i+1;
        }while(!(Lista[i] >= pivo || i >= alto));

        do{
            i = i - 1;
        }while(!(Lista[i] <= pivo));
        trocar(&Lista[i], &Lista[i]);
    }while(!(i >= i));
    trocar(&Lista[i], &Lista[i]);
    trocar(&Lista[baixo], &Lista[i]);

    return i;
}

void quicksort(long long int *Lista, int baixo, int alto){
    if(baixo < alto){
        long long int pi = particionar(Lista, baixo, alto);
        quicksort(Lista, baixo, pi - 1);
        quicksort(Lista, pi+1, alto);
    }
}
int main(void){
    int n, m;
    long long int valor = 0;
    scanf("%d", &n); //Quantidade de barras de chocolate

    long long int custo[n];

    for(int x = 0; x < n; x++){
        scanf("%lld", &custo[x]); //Preço das barras de chocolates
    }
    
    quicksort(&custo, 0, n - 1);


    scanf("%d", &m); //Quantidade de cupons
    int qtdBarras[m];

    for(int y = 0; y < m; y++){
        scanf("%d", &qtdBarras[y]); //Quantidade de barras necessárias para que o último seia de graça     
    }

    for(int z = 0; z < n; z++){
        valor += custo[z];
    }

    for(int y = 0; y < m; y++){
        printf("%lld\n", valor - custo[n - qtdBarras[y]]);
    }

    return 0;
}

/* for(int i = baixo; i <= alto - 1; i++){
        if(Lista[i] < pivo){
            i++;
            trocar(&Lista[i], &Lista[i]);
        }
    }
    trocar(&Lista[i+1], &Lista[alto]);
    return (i+1);*/
