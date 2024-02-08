#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph{
    public:
        Graph *create_graph(int n){
            Graph *g = new Graph;
            g->Mark = new bool[n];
            g->matrix = new int* [n];
            for(int i{}; i < n; i++){
                g->matrix[i] = new int[n];
                for(int j{}; j < n; j++){
                    g->matrix[i][j] = 0;
                }
            }
            g->numEdge = 0;
            g->countNode = n;
            return g;
        }

        void setEdge(Graph *g, int i, int j, int wt){
            if(wt != 0){
                if(g->matrix[i][j] == 0 && g->matrix[j][i] == 0){
                    g->numEdge++;
                }
                g->matrix[i][j] = wt;
                g->matrix[j][i] = wt;
            }
        }

        void DFS(int v){
            cout << "Iniciando a visita do no:" << v << endl;
            setMark(this, v, true);
            int w = first(this, v);
            while(w < countNode){
                if(getMark(this, w) == false){
                    DFS(w);
                    w = next(this, v, w);
                }
            }
            cout << "Finalizando a visita do no:" << v << endl;
        }

        void BFS(int start){
            queue<int> Q;
            int v, w;
            Q.push(start);
            setMark(this, start, true);
            
            while(Q.size() > 0){
                v = Q.front();
                Q.pop();
                
                cout << "o no:" << v << "Foi removido" << endl;
                w = first(this, v);

                while(w < countNode){
                    if(getMark(this, w) == false){
                        setMark(this, w, true);
                        Q.push(w);
                    }
                    w = next(this, v, w);
                }
            }

            
            cout << "BFS FINALIZADO" << endl;    
        }


    private:
        int **matrix;
        int numEdge;
        bool *Mark;
        int countNode;

        void graphTraverseDFS(Graph *g){
            for(int v{}; v <= g->countNode - 1; v++){
                setMark(g, v, false);
            }
            for(int v{}; v <= g->countNode - 1; v++){
                if(getMark(g, v) == false){
                    DFS(v);
                }
            }
        }

        void graphTraverseBFS(){
            for(int v{}; v <= countNode; v++){
                setMark(this, v, false);
            }
            for(int v{}; v <= countNode; v++){
                if(getMark(this, v) == false)
                    BFS(v);
            }
        }

        int first(Graph *g, int v){
            for(int i{}; i <= g->countNode - 1; i++){
                if(g->matrix[v][i] != 0){
                    return i;
                }
            }
            return g->countNode;
        }

        int next(Graph *g, int v, int w){
            for(int i = w + 1; i <= g->countNode - 1; i++){
                if(g->matrix[v][i] != 0){
                    return i;
                }
            }
            return g->countNode;
        }

        void delEdge(Graph *g, int i, int j){
            if(g->matrix[i][j] != 0){
                g->numEdge--;
            }
            g->matrix[i][j] = 0;
        }

        void setMark(Graph *g, int v, bool var){
            if(var == true)
                g->Mark[v] = true;
            else
                g->Mark[v] = false;
        }

        bool getMark(Graph *g, int v){
            if(g->Mark[v] == true){
                return true;
            }
            else{
                return false;
            }
        }

        void toposort(Graph *g, int v, stack<int> s){
            setMark(g, v, true);
            int w = first(g, v);

            while(w < g->countNode){
                if(getMark(g, w) == false){
                    toposort(g, w, s);
                }
                w = next(g, v, w);
            }
            s.push(v);
        }
};


int main(void){
    int n, q;

    cin >> n >> q;

    Graph *grafo = new Graph;
    grafo = grafo->create_graph(n);

    for(int i{}; i < q; i++){
        string op;
        int u, v;

        cin >> op;

        if(op == "add"){
            cin >> u >> v;

            grafo->setEdge(grafo, u, v, 1);
        }
        else if(op == "BFS"){
            cin >> v;

            grafo->BFS(v);
        }
        else if(op == "DFS"){
            cin >> v;

            grafo->DFS(v);
        }
    }
    return 0;
}

