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
            g->matrix = new int[n];
            for(int i{}; i < n; i++){
                g->matrix[i] = new int[n];
            }
            g->numEdge = 0;
            g->countNode = n;
            return g;
        }
    
        void graphTraverseDFS(Graph *g){
            for(v{}; v <= g->countNode - 1; v++){
                setMark(g, v, false);
            }
            for(v{}; v <= count - 1; v++){
                if(getMark(g, v) == false){
                    DFS(g, v);
                }
            }
        }

        void graphTraverseBFS(Graph *g){
            for(int v{}; v <= g->countNode; v++){
                setMark(g, v, "UNVISITED");
            }
            for(int v{}; v <= g->countNode; v++){
                if(getMark(g, v) == "UNVISITED")
                    BFS(g, v);
            }
        }

        void setEdge(Graph *g, int i, int j, int wt){
            if(wt == 0); break;
            if(g->matrix[i][j] == 0 && g->matrix[j][i] == 0){
                g->numEdge++;
            }
            g->matrix[i][j] = wt;
            g->matrix[j][i] = wt;
        }


    private:
        int **matrix;
        int numEdge;
        bool *Mark;
        int countNode;

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

        void DFS(Graph *g, int v){
            cout << "Iniciando a visita do nó:" << v << endl;
            setMark(g, v, true);
            int w = first(g, v);
            while(w < g->countNode){
                if(getMark(g, w) == false){
                    DFS(g, w);
                    w = next(g, v, w);
                }
            }
            cout << "Finalizando a visita do nó:" << v << endl;
        }

        void BFS(Graph *g, int start){
            queue<int> Q;
            Q.push(start);
            setMark(g, start, true);

            while(Q.size() > 0){
            int v = Q.pop();
            cout << "o nó:" << v << "Foi removido" << endl;
            int w = first(g, v);
            }

            while(w < g->countNode){
                if(getMark(g, w) == false){
                    setMark(g, w, true);
                    Q.push(w);
                }
                w = next(g, v, w);
            }
            cout << "BFS FINALIZADO" << endl;    
        }

        void toposort(Graph *g, int v, stack s){
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
}


int main(void){
    int n, q;
    cin >> n >> q;

    Graph *grafo1;
    grafo1->create_graph(n);

    string op;
    int u, v;

    for(int i{}; i < q; i++){
        cin >> op >> u >> v;

        switch (op)
        {
        case "add":
            grafo1->setEdge(grafo1, u, v, )
            break;
        
        case "BFS":

            break;

        case "DFS":

            break;
        default:
            break;
        }
    }

    return 0;
}

