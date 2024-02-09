#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph{
    public:
        Graph *create_graph(int n, int m){
            Graph *g = new Graph;
            g->Mark = new bool[n];
            g->listaAdj = new list<int>[n];
            for(int i{}; i < n; i++){
                listaAdj[i] = list<int>();
            }
            g->numEdge = m;
            g->countNode = n;
            return g;
        }

        void setEdge(int i, int j){
            listaAdj[i].push_back(j);
        }

        void toposort(int v, stack<int> s){
            setMark(v, true);
            int w = first(v);

            while(w < countNode){
                if(getMark(w) == false){
                    toposort(w, s);
                }
                w = next(v, w);
            }
            s.push(v);
        }

    private:
        list<int> *listaAdj;
        int numEdge;
        bool *Mark;
        int countNode;

        int first(int v){
            if(!listaAdj[v].empty()){
                return listaAdj[v].front();
            }
            return countNode;
        }

        int next(int v, int w){
            auto elem = listaAdj[v].begin();

            if(!listaAdj[v].empty()){
                for(int elemento : listaAdj[v]){
                    if(elemento == w){
                        ++elem;
                        if(elem != listaAdj[v].end()){
                            return *elem;
                        }
                    }
                    elem++;
                }
            }
            return countNode;
        }

        void setMark(int v, bool var){
            if(var == true)
                Mark[v] = true;
            else
                Mark[v] = false;
        }

        bool getMark(int v){
            if(Mark[v] == true){
                return true;
            }
            else{
                return false;
            }
        }

        
};

int main(void){
    int n, m;

    cin >> n >> m;

    Graph *grafo = new Graph;
    grafo = grafo->create_graph(n, m);

    for(int i{}; i < m; i++){
        int u, v;

        cin >> u >> v;

        grafo->setEdge(u, v);
    }

    cout << "deu certo";
    return 0;
}