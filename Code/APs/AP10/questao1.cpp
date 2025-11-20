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

        void setEdge(int i, int j, int wt){
            if(wt != 0){
                if(matrix[i][j] == 0 && matrix[j][i] == 0){
                    numEdge++;
                }
                matrix[i][j] = wt;
                matrix[j][i] = wt;
            }
        }

        void graphTraverseDFS(int ver){
            for(int v{}; v <= countNode - 1; v++){
                setMark(v, false);
            }
            for(int v = ver; v <= countNode - 1; v++){
                if(getMark(v) == false){
                    DFS(v);
                }
            }
        }

        void graphTraverseBFS(int ver){
            for(int v{}; v <= countNode - 1; v++){
                setMark( v, false);
            }
            for(int v = ver; v <= countNode - 1; v++){
                if(getMark(v) == false)
                    BFS(v);
            }
        }

    private:
        int **matrix;
        int numEdge;
        bool *Mark;
        int countNode;

        void DFS(int v){
            cout << v << " ";
            setMark(v, true);
            int w = first(v);
            while(w < countNode){
                if(getMark(w) == false){
                    DFS(w);
                }
                w = next(v, w);
            }
        }

        void BFS(int start){
            queue<int> Q;
            int v, w;
            Q.push(start);
            setMark(start, true);
            
            while(Q.size() > 0){
                v = Q.front();
                Q.pop();
                
                cout << v << " ";
                w = first(v);

                while(w < countNode){
                    if(getMark( w) == false){
                        setMark(w, true);
                        Q.push(w);
                    }
                    w = next(v, w);
                }
            }  

            cout << endl;
        }

        int first(int v){
            for(int i{}; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
        }

        int next(int v, int w){
            for(int i = w + 1; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
        }

        void delEdge(Graph *g, int i, int j){
            if(g->matrix[i][j] != 0){
                g->numEdge--;
            }
            g->matrix[i][j] = 0;
        }

        

        bool getMark(int v){
            if(Mark[v] == true){
                return true;
            }
            else{
                return false;
            }
        }

        void toposort(Graph *g, int v, stack<int> s){
            setMark(v, true);
            int w = first(v);

            while(w < g->countNode){
                if(getMark(w) == false){
                    toposort(g, w, s);
                }
                w = next(v, w);
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

            grafo->setEdge(u, v, 1);
        }
        else if(op == "BFS"){
            cin >> v;

            grafo->graphTraverseBFS(v);
        }
        else if(op == "DFS"){
            cin >> v;

            grafo->graphTraverseDFS(v);
            cout << endl;
        }
    }
    return 0;
}

