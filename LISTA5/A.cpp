#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        Graph (int v){
            in = new int[v+1];
            listaAdj = new vector<int>[v+1];
            for(int i = 0; i <= v; i++){
                this->listaAdj[i].reserve(v+1);
            }
            
        }
        vector<int> *listaAdj;
        int *in;
        vector<int> res;

        void setEdge(int i, int j){
            listaAdj[i].push_back(j);
        }

        bool toposort(int v){
            priority_queue<int, vector<int>, greater<int>> q;
            for(int i = 1; i <= v; i++){
                if(in[i] == 0){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int curr = q.top();
                res.push_back(curr);
                q.pop();
                for(int node : listaAdj[curr]){
                    in[node]--;
                    if(in[node] == 0){
                        q.push(node);
                    }
                }                
            }
            return (res.size() == v);
        }

    private:
        bool *Mark;
        int countNode;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    Graph grafo(n);

    for(int i = 1; i <= m; i++){
        int x, y;

        cin >> x >> y;

        grafo.setEdge(x , y);
        grafo.in[y]++;
    }

    if(!grafo.toposort(n)){
        cout << "Sandro fails.\n";
    }
    else{
        for(int i = 0; i < grafo.res.size(); i++){
            cout << grafo.res[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}