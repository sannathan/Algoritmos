#include <iostream>

using namespace std;

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

    void setEdge(int src, int dest, int weight) {
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

int main(void){
    int N;

    cin >> N;

    for(int i{}; i < N; i++){
        int n, m, S, T;

        cin >> n >> m >> S >> T;

        Graph internet(n);
        for(int j{}; j < m; j++){
            int a, b, w;
            
            cin >> a >> b >> w;

            internet.setEdge(a, b, w);
        }

        vector<int> distances = internet.dijkstra(S);

        if(distances[T] == numeric_limits<int>::max())
            cout << "Case #" << i+1 << ": unreachable" << endl;
        else
            cout << "Case #" << i+1 << ": " << distances[T] << endl;
    }
    return 0;
}