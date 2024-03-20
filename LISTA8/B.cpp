#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int path(int n, int index, int K, vector<int>& Height, vector<int>& dp){
    if(index > n){
        return INT_MAX;
    }
    if(index == n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int minSum = INT_MAX;
    for(int i = 1; i <= K; i++){
        if(index + i <= n){
            int diff = abs(Height[index] - Height[index + i]);
            minSum = min(minSum, diff + path(n, index + i, K, Height, dp));
        }
    }
    dp[index] = minSum;
    return minSum;

}
int main() {
    int N, K;

    cin >> N >> K;

    vector<int> Height(N+1, INT_MAX);
    vector<int> dp(N+1, -1);

    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        Height[i] = x;
    }

    cout << path(N, 1, K, Height, dp) << endl;

    return 0;
}

/*for(int i = index; i <= K; i++){
        sum[i] = Height[index] - Height[i+1];
            if(sum[i] < 0){
                sum[i] *= -1;
            }
        minorSum[i].first += sum[i];
        minorSum[i].second = i+1;


        else{
            for(int j = i; j <= i + K; j++){
                path(n, minorSum[j].second, minorSum[j].second + K, Height, sum, minorSum);
                if(resultado[j] < resultado[j - 1]){
                    menor = resultado[j];
                }
            }

        }
    }*/