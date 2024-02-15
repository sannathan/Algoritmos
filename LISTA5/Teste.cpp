#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        vector<int> listaAdj[10001];
        int in[10001];
        vector<int> res;
        bool *Mark = new bool[10001];
        bool *recStack = new bool[10001];
        int countNode;
        stack<int> Stack;

        void setEdge(int i, int j){
            listaAdj[i].push_back(j);
        }

        int first(int v){
            if(!listaAdj[v].empty()){
                return listaAdj[v].front();
            }
            return countNode;
        }

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool getMark(int v){
            return Mark[v];
        }

        int next(int v, int w){
            auto elem = listaAdj[v].begin();

            while(elem != listaAdj[v].end() && *elem != w){
                ++elem;
            }
            if(elem != listaAdj[v].end() && *elem == w){
                ++elem;
                if(elem != listaAdj[v].end()){
                    return *elem;
                }
            }
            return countNode;
        }

        bool DFS(int v){
            setMark(v, true);
            recStack[v] = true;

            for(auto i = listaAdj[v].begin(); i != listaAdj[v].end(); ++i){
                if (!Mark[*i] && DFS(*i))
                    return true;
                else if (recStack[*i])
                    return true;
            }

            recStack[v] = false;  // remove o vértice da pilha de recursão
            Stack.push(v);
            return false;
        }

        void toposort(int v){
            setMark(v, true);
            int w = first(v);

            while(w < countNode){
                if(!getMark(w)){
                    DFS(w);
                }
                w = next(v, w);
            }

            while(!Stack.empty()){
                res.push_back(Stack.top());
                Stack.pop();
            }
        }
};
    

    

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Graph grafo;

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
