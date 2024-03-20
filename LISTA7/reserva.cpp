#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
void DFS(int x, int y, vector<vector<int>>& adj, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < adj.size() && ny >= 0 && ny < adj[0].size() && !visited[nx][ny]){
            DFS(nx, ny, adj, visited);
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

        vector<vector<int>> tabuleiro(10, vector<int>(10, -1));
        vector<vector<bool>> visited(10, vector<bool>(10, false));
        vector<int> somas(n, 0);

        for(int i{}; i < n; i++){
            int x, y;

            cin >> x >> y;

            for(int j{}; j < x+y; j++){
                if(j < x){
                    tabuleiro[i][j] = 0;
                }
                else{
                    tabuleiro[i][j] = 1;
                }
            }
        }

        DFS(0, 0,tabuleiro, visited);

        int squares = 0;

        for(int i{}; i < visited.size(); i++){
            for(int j{}; j < visited[i].size(); j++){
                if(visited[i][j] == true && tabuleiro[i][j] ==){
                    squares++;
                }
            }
        }

        cout << "Case " << s+1 << ", " << 8 - squares << " squares can not be reached." << endl;
        s++;
    }
    return 0;
}