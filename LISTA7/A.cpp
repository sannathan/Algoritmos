#include <iostream>
#include <vector>

using namespace std;

void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            DFS(adj[v][i], adj, visited);
        }
    }
}

int main(void){
    int s = 0;
    while(true){
        int n;

        cin >> n;
        
        if(n == 0){
            break;
        }

        vector<vector<int>> tabuleiro(n, vector<int>(n, 0));
        vector<bool> visited(n, false);
        vector<int> somas(n, 0);

        for(int i{}; i < n; i++){
            int x, y;

            cin >> x >> y;

            somas[i] = x+y;

            for(int j{}; j < x+y; j++){
                if(j < x){
                    tabuleiro[i][j] = 0;
                }
                else{
                    tabuleiro[i][j] = 1;
                }
            }
        }

        DFS(0, tabuleiro, visited);

        int squares = 0;

        for(int i{}; i < n; i++){
            if(visited[i] == false){
                squares++;
            }
        }

        cout << "Case " << s+1 << ", " << squares << " squares can not be reached." << endl;
    }
    return 0;
}