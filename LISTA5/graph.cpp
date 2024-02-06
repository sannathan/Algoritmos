#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph{

    public:
        list <int> *matrix;
        int numEdge;
        int *Mark;
        int countNode;

        Graph *create_graph(int n){
            Graph *g = new Graph;
            g->Mark = new int[n];
            g->matrix = new list[n];
            for(int i{}; i < n; i++){
                g->matrix[i] = new list[n];
            }
            g->countNode = 0;
            g->numEdge = 0;
            return g;
        }
    
        void graphTraverseDFS(Graph *g, int count){
            for(v = 0; v <= count - 1; v++){
                setMark(g, v, "UNVISITED");
            }
            for(v{}; v <= count - 1; v++){
                if(getMark(g, v) == "UNVISITED"){
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


    private:

        int first(Graph *g, int v, int count){
            for(int i{}; i <= count - 1; i++){
                if(g->matrix[v][i] != 0){
                    return i;
                }
            }
            return count;
        }

        int next(Graph *g, int v, int w, int count){
            for(int i = w + 1; i <= count - 1; i++){
                if(g->matrix[v][i] != 0){
                    return i;
                }
            }
            return count;
        }

        void setEdge(Graph *g, int i, int j, int wt){
            if(wt == 0); break;
            if(g->matrix[i][j] = 0){
                g->numEdge++;
            }
            g->matrix[i][j] = wt;
        }

        void delEdge(Graph *g, int i, int j){
            if(g->matrix[i][j] != 0){
                g->numEdge--;
            }
            g->matrix[i][j] = 0;
        }
}
        void DFS(Graph *g, int v, int count){
            cout << "Iniciando a visita do nó:" << v << endl;
            setMArk(g, v, "VISITED");
            w = first(g, v, count);
            while(w < count){
                if(getMark(g, w) == "UNVISITED"){
                    DFS(g, w, count);
                    w = next(g, v, w);
                }
            }
            cout << "Finalizando a visita do nó:" << v << endl;
        }

        void BFS(Graph *g, int start){
            queue<int> Q;
            Q.push(start);
            setMark(g, start, "VISITED");

            while(Q.size() > 0){
            int v = Q.pop();
            cout << "o nó:" << v << "Foi removido" << endl;
            int w = first(g, v, g->countNode);
            }

            while(w < g->countNode){
                if(getMark(g, w) == "UNVISITED"){
                    setMark(g, w, "VISITED");
                    Q.push(w);
                }
            }    
        }






// void graphTraverse2(Graph *g, int count){
//     for(v = 0; v < count - 1; v++){
//         setMArk(g, v, "UNVISITED");
//     }
//     for(v = 0; v < count - 1; v++){
//         if(getMark(g, v) == "UNVISITED"){
//             DFS(g, v);
//         }
//     }
// }

int main(void){
    return 0;
}

