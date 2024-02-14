#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    public:

        Graph(int n){
            listaAdj = new list<int>[n];
            countNode = n;
            Mark = new bool[n];
            for(int i{}; i < n; i++){
                listaAdj[i] = list<int>();
                Mark[i] = false;
            }
        }

        ~Graph(){
            delete[] listaAdj;
            delete[] Mark;
        }

        void setEdge(int i, int j){
            listaAdj[i-1].push_back(j);
        }

        void toposort(int v, stack<int> *s){
            setMark(v, true);
            int w = first(v);

            while(w < countNode){
                if(!getMark(w)){
                    toposort(w, s);
                }
                w = next(v, w);
            }
            s->push(v);
        }
    private:
        list<int> *listaAdj;
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
                if(elem != listaAdj[v].end()){
                    return *elem;
                }
            }
            return countNode;
        }

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool getMark(int v){
            return Mark[v];
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
            auxx = i;
        }

        grafo.setEdge(x , y);
    }

    grafo.toposort(auxx, s);

    list <int> aux;

    while(!s->empty()){
        aux.emplace_front(s->top());
        s->pop();
    }

    auto elem = aux.begin();

    while(elem != aux.end()){
        cout << *elem << " ";
        ++elem;
    }

    delete s;
    grafo.~Graph();
    return 0;
}