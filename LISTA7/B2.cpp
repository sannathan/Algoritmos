#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, traps;
};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(j + 1)));

    queue<Node> q;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++) {
            cin >> maze[i][k];
            if(maze[i][k] == '@') {
                q.push({i, k, j});
                visited[i][k][j] = true;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()) {
        Node node = q.front();
        q.pop();

        if(maze[node.x][node.y] == 'x' && node.traps >= 0) {
            cout << "SUCCESS\n";
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int newX = node.x + dx[i];          
            int newY = node.y + dy[i];
            int newTraps = node.traps - (maze[node.x][node.y] == 's');

            if(isValid(newX, newY, n, m) && newTraps >= 0 && !visited[newX][newY][newTraps]) {
                if (maze[newX][newY] == '.' || maze[newX][newY] == 'x'){
                    q.push({newX, newY, newTraps});
                    visited[newX][newY][newTraps] = true;
                }
                else if (maze[newX][newY] == 's' && newTraps > 0){
                     q.push({newX, newY, newTraps - 1});
                    visited[newX][newY][newTraps-1] = true;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}