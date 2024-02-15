#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph{
    public:

        Graph(int n){
            listaAdj = new vector<vector<int>>[n];
            countNode = n;
            Mark = new bool[n];
            for(int i{}; i < n; i++){
                Mark[i] = false;
            }
        }

        ~Graph(){
            delete[] listaAdj;
            delete[] Mark;
        }

        void setEdge(int i, int j){
            if(i < countNode && j < countNode){
                listaAdj[i].push_back(j);
            }
        }

        bool toposort(int v, stack<int> *s){
            setMark(v, true);
            int w = first(v);

            while(w < countNode){
                if(!getMark(w)){
                    if(detectCycle(w)){
                        delete s;
                        return false;
                    }
                    if(!toposort(w, s)){
                        return false;
                    }
                }
                w = next(v, w);
            }
            s->push(v);
            return true;
        }

    private:
        vector<vector<int>> *listaAdj;
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

            while(elem != listaAdj[v].end() && *elem != w){
                ++elem;
            }
            if(elem != listaAdj[v].end() && *elem == w){
                ++elem;
                return (elem != listaAdj[v].end()) ? *elem : countNode;
            }
            return countNode;
        }

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool getMark(int v){
            return Mark[v];
        }

        bool detectCycleDFS(int v, bool *visited, bool *recStack){
            visited[v] = true;
            recStack[v] = true;

            for(auto it = listaAdj[v].begin(); it != listaAdj[v].end(); ++it){
                int w = *it;

                if(!visited[w]){
                    if(detectCycleDFS(w, visited, recStack)){
                        return true;
                    }
                }

                else if(recStack[w]){
                    return true;
                }
            }

            recStack[v] = false;
            return false;
        }
        bool detectCycle(int v){
            bool *visited = new bool[countNode];
            bool *recStack = new bool[countNode];

            bool cycle = detectCycleDFS(v, visited, recStack);

            delete[] visited;
            delete[] recStack;

            return cycle;
        }
};

int main(void){
    int n, m, auxx;

    cin >> n >> m;

    Graph grafo(n);
    stack <int> *s = new stack<int>;

    for(int i = 1; i <= m; i++){
        int x, y;

        cin >> x >> y;

        if(i == 1){
            auxx = x;
        }

        grafo.setEdge(x , y);
    }

    bool e = grafo.toposort(auxx, s);
    if(!e){
        cout << "Sandro fails.";
    }
    
    return 0;
}