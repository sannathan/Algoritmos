#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(int start, vector<vector<pii>>& adj) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int city1, city2, length;
        cin >> city1 >> city2 >> length;
        adj[city1].push_back({city2, length});
        adj[city2].push_back({city1, length});
    }

    int maxDistance = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> dist = dijkstra(i, adj);

        for (int j = 0; j < n; ++j) {
            if (i != j && dist[j] == numeric_limits<int>::max()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

            maxDistance = max(maxDistance, dist[j]);
        }
    }

    cout << maxDistance << endl;

    return 0;
}