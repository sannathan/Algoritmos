#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, trapsLeft;
    Point(int _x, int _y, int _trapsLeft) : x(_x), y(_y), trapsLeft(_trapsLeft) {}
};

bool isValid(int x, int y, int n, int m);
bool canReachTreasure(vector<vector<char>>& maze, int n, int m, int traps, int startX, int startY);

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    bool foundTreasure = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '@') {
                if (canReachTreasure(maze, n, m, j, i, j)) {
                    foundTreasure = true;
                    break;
                }
            }
        }
        if (foundTreasure) {
            break;
        }
    }

    if (foundTreasure) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

bool canReachTreasure(vector<vector<char>>& maze, int n, int m, int traps, int startX, int startY) {
    vector<pair<int, int>> df = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    queue<Point> q;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(traps + 1, false)));

    q.push(Point(startX, startY, traps));

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int trapsLeft = current.trapsLeft;

        if (maze[x][y] == 'x' && trapsLeft >= traps / 2) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + df[i].first;
            int newY = y + df[i].second;

            if (isValid(newX, newY, n, m) && !visited[newX][newY][trapsLeft]) {
                if (maze[newX][newY] == '.' || maze[newX][newY] == 'x') {
                  
                    q.push(Point(newX, newY, trapsLeft));
                    visited[newX][newY][trapsLeft] = true;
                } else if (maze[newX][newY] == 's' && trapsLeft > 0) {
                   
                    q.push(Point(newX, newY, trapsLeft - 1));
                    visited[newX][newY][trapsLeft - 1] = true;
                }
            }
        }
    }

    return false;
}

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}