#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
};

class Graph {
public:
    Graph(int n) : countNode(n), adjList(n) {}

    void setEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    int Prim(int startVertex, int m){
        vector<int> D(countNode, numeric_limits<int>::max());
        vector<bool> visited(countNode, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> H;

        D[startVertex] = 0;
        H.push({0, startVertex});

        while(!H.empty()){
            int u = H.top().second;
            H.pop();

            if(visited[u]) continue;
                visited[u] = true;

            for(const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if(!visited[v] && D[v] > weight){
                    D[v] = weight;
                    H.push({D[v], v});
                }
            }
        }

        int alcance_minimo = 0;
        for(int i{}; i < countNode; i++){
            if(D[i] == numeric_limits<int>::max()) return -1;
            alcance_minimo = max(alcance_minimo, D[i]);
        }

        return alcance_minimo;
    }

private:
    int countNode;
    vector<vector<pair<int, int>>> adjList;
};

int main() {
    while(true){
        int n, m;

        cin >> n >> m;

        if(n == 0 && m == 0){
            break;

        }
        Graph GPS(n);
        for(int i{}; i < m; i++){
            int city1, city2, length;

            cin >> city1 >> city2 >> length;

            GPS.setEdge(city1, city2, length);
        }

        int distancias = GPS.Prim(0, m);

        if(distancias == -1){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << distancias << endl;
        }
        
    }
    return 0;
}