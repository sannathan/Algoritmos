#include <iostream>

using namespace std;

int Knapsack(int n, int W, int *w, int *v, int **F){
    for(int i{}; i <= n; i++){
        for(int j{}; j <= W; j++){
            if(i == 0 || j == 0){
                F[i][j] = 0;
            }
            else if(w[i] <= j){
                F[i][j] = max(F[i - 1][j], v[i] + F[i - 1][j - w[i]]);
            }
            else{
                F[i][j] = F[i - 1][j];
            }
        }
    }
    return F[n][W];
}

int main(void){
    int S, N;

    cin >> S >> N;

    int *weight = new int[N+1];
    int *value = new int[N+1];
    int **F = new int *[N+1];
    for(int i{}; i <= N; i++){
        F[i] = new int[S+1];
    }

    for(int i = 1; i <= N; i++){
        int x, y;

        cin >> x >> y;

        weight[i] = x;  
        value[i] = y;
    }

    int Resultado = Knapsack(N, S, weight, value, F); 

    cout << Resultado << endl;

    delete[] weight;
    delete[] value;
    for(int i{}; i <= N; i++){
        delete[] F[i];
    }
    delete[] F;
    return 0;
}