#include <iostream>

using namespace std;

void HeapBottomUp(int *cost, int N){
    for(int i = N/2; i >= 1; i--){ 
        int k = i;
        int v = cost[k];
        bool heap = false;

        while(!heap && 2*k <= N){
            int j = 2*k;
            if(j < N){
                if(cost[j] < cost[j+1]){
                    j = j + 1;
                }
            }
            if(v >= cost[j]){
                heap = true;
            }
            else{
                cost[k] = cost[j];
                k = j;
            }
        }
        cost[k] = v;
    }
}
int main(void){
    int N = 1, sum = 0;

    while(N != 0){
        cin >> N;
        int *cost = new int[N];
        int totalCost = 0;

        for(int i = 1; i <= N; i++){
            cin >> cost[i];
            if(i == 1){
                sum += cost[i];
            }
            else{
                sum += cost[i];
                totalCost += sum;
            }
        }

        
        delete [] cost;
        if(totalCost != 0){
            cout << totalCost << endl;
        }
        sum = 0;
    }

    return 0;
}

/*int N = 1, sum = 0;

    while(N != 0){
        cin >> N;
        int *cost = new int[N];
        int totalCost = 0;

        for(int i = 1; i <= N; i++){
            cin >> cost[i];
            if(i == 1){
                sum += cost[i];
            }
            else{
                sum += cost[i];
                totalCost += sum;
            }
        }
        delete [] cost;
        cout << totalCost << endl;
        sum = 0;
    }*/

/*
HeapBottomUp(cost, N);

        while(N > 1){
            int a = cost[1];
            cost[1] = cost[N];
            N--;
            HeapBottomUp(cost, N);
            int b = cost[1];
            cost[1] = cost[N];
            HeapBottomUp(cost, N);
            int soma = a + b;
            totalCost += soma;
            cost[N+1] = soma;
            N++;
            HeapBottomUp(cost, N);
        }*/