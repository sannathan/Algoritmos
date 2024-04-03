#include <iostream>
#include <vector>

using namespace std;


bool SpikyMazes(vector<vector<char>>& maze, vector<vector<vector<bool>>>& visited, int j, int x, int y, int& s){
     if(x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || visited[x][y][j] == -1) {
        return false;
    }

    if(maze[x][y] == '#') {
        return false;
    }

    if(maze[x][y] == 's' && j == 0) {
        return false;
    }

    if(maze[x][y] == 's' && j > 0) {
        j--;
    }

    if(maze[x][y] == 'x' && s == 0) {
        s++;
    }

    if(maze[x][y] == '@' && s == 1 && j >= 0) {
        return true;
    }

    visited[x][y][j] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        if(SpikyMazes(maze, visited, j, x + dx[i], y + dy[i], s)) {
            return true;
        }
    }

    return false;
}

int main(void){
    int n, m, j;

    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(j + 1, false)));

    vector<pair<int, int>> starts;

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> maze[i][j];

            if(maze[i][j] == '@'){
                starts.push_back({i, j});
            }
        }
    }

    int s = 0;
    for(auto start : starts) {
        if(SpikyMazes(maze, visited, j, start.first, start.second, s)){
            cout << "SUCCESS";
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}