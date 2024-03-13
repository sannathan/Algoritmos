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
    
    return 0;
}