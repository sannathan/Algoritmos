#include <iostream>
#include <queue>
#include <bits/stdc++.h> 

using namespace std;

struct ComparePairs{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
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
                listaAdj[n].reserve(n);
            }
        }

        ~Graph(){
            //delete [] D;
            delete [] P;
            delete [] Mark;
        }

        int countNode;
        //int *D;
        int *P;
        vector<pair<int, int>> *listaAdj;
        bool *Mark;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, ComparePairs> H;

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool GetMark(int v){
            return Mark[v];
        }

        int next(int v, int w){
            for(int i = w + 1; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
        }

        int first(int v){
            for(int i{}; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
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

        void Dijkstra(int s, int *D){
            pair<pair<int, int>, int> pv;

            D = new int[countNode];

            for(int i = 0; i < countNode; i++){
                D[i] = countNode + 1;
                P[i] = -1;

                setMark(i, false);
            }
            H.push({{s, s}, 0});
            D[s] = 0;
            for(int i = 0; i < countNode; i++){
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
                int w = first(pv.first.second);
                while(w < countNode){
                    if(GetMark(w) != true && D[w] > (D[pv.first.second] + weight(pv.first.second, w, D))){
                        D[w] = D[pv.first.second] + weight(pv.first.second, w, D);
                        H.push({{pv.first.second, w}, D[w]});
                    }
                    w = next(pv.first.second, w);
                }
            } 
        }       
};

int main(void){
    int n, m, v;

    cin >> n >> m >> v;

    Graph grafo(n);

    for(int i{}; i < m; i++){
        int a, b, w;

        cin >> a, b, w;

        grafo.setEdge(a, b, w);
    }

    int *D;
    grafo.Dijkstra(0, D)

    return 0;
}