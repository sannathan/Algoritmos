#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

struct ComparePairs{
    bool operator()(const pair<int, int>& p1, const pair<pair<int, int>, int>& p2){
        return p1.second > p2.second;
    }
};

class Graph{
    public:
        Graph (int n){
            countNode = n;
            P = new int [n];
            Mark = new bool [n];
            listaAdj = new vector<pair<int, int>>[n];
            
            for(int i{}; i < n; i++){
                listaAdj[i] = vector<pair<int, int>>(1,make_pair(0, 0));
            }
        }

        ~Graph(){
            delete [] P;
            delete [] Mark;
        }

        int *P;
        bool *Mark;

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool GetMark(int v){
            return Mark[v];
        }

        int next(int v, int w){
            if(!listaAdj[v].empty()){
                if(w >= 0 && w < listaAdj[v].size() - 1){
                    for(int i = w + 1; i < listaAdj[v].size(); i++){
                        if(listaAdj[v][i].first != 0 && listaAdj[v][i].second != 0){
                            return i;
                        }
                    }
                }
            }
            return countNode;
        }

        pair<int, int> first(int v){
            if(!listaAdj[v].empty()){
                return listaAdj[v][0];
            }
            return make_pair(countNode, countNode);
        }

        int weight(int v, int w, int *D){
            int cost = D[w];
            if(v > w){
                for(int i = w; i > v; --i){
                    cost += D[P[i]];
                }
            }
            else{
                for(int i = v; i > w; --i){
                    cost += D[P[i]];
                }
            }
            
            return cost;
        }

        void setEdge(int i, int j, int w){
            listaAdj[i].push_back({j, w});
            listaAdj[j].push_back({i, w});
        }

        vector<int> Dijkstra(int s){
            vector<int> D(countNode, numeric_limits<int>::max());
            D[s] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> H;
            H.push({s, 0});

            while(!H.empty()){
                int pv = H.top().first;
                H.pop();

                for(const auto& edge : listaAdj[pv]){
                    int v = edge.first;
                    int weight = edge.second;

                    if(D[v] > D[pv] + weight){
                        D[v] = D[pv] + weight;
                        H.push({v, D[v]});
                    }
                }
            }

            return D;
            /*   for(int i = 0; i < countNode; i++){
                    do{
                        if(H.size() > 0){
                            pv = H.top();
                            H.pop();
                        }
                        else{
                            return;
                        }
                    }while(!(GetMark(pv.first.second) == false));

                    setMark(pv.first.second, true);
                    P[pv.first.second] = pv.first.first;
                    pair<int, int> w = first(pv.first.second);

                    while(w.first != countNode){
                        if(GetMark(w.first) != true && D[w.first] > (D[pv.first.second] + weight(pv.first.second, w.first, D))){
                            D[w.first] = D[pv.first.second] + weight(pv.first.second, w.first, D);
                            H.push({{pv.first.second, w.first}, D[w.first]});
                        }
                        w.first= next(pv.first.second, w.first);
                    }
                }*/ 
            }
    private:
        int countNode;
        vector<vector<pair<int, int>>> listaAdj;
};

int main(void){
    int n, m, v;

    cin >> n >> m >> v;

    Graph grafo(n);

    for(int i{}; i < m; i++){
        int a, b, w;

        cin >> a >> b >> w;

        grafo.setEdge(a, b, w);
    }

    vector<int> distancia = grafo.Dijkstra(0);

    for(int d : distancia){
        if(d == numeric_limits<int>::max()){
            cout << "-1 ";
        }
        else{
            cout << d << " ";
        }
    }

    return 0;
}