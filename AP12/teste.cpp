#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

class Graph {
public:
    Graph(int n) : countNode(n), adjList(n) {}

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight)); // Para arestas não-dirigidas
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(countNode, numeric_limits<int>::max());
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;
        pq.push(make_pair(start, 0));

        while (!pq.empty()) {
            int u = pq.top().first;
            pq.pop();

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(v, dist[v]));
                }
            }
        }

        return dist;
    }

private:
    int countNode;
    vector<vector<pair<int, int>>> adjList;
};

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    vector<int> distances = graph.dijkstra(v);

    for (int d : distances) {
        if (d == numeric_limits<int>::max())
            cout << -1 << " ";
        else
            cout << d << " ";
    }
    cout << endl;

    return 0;
}
