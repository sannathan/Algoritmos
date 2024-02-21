#include <iostream>
#include <queue>

using namespace std;

class Graph{
    public:
        Graph (int n){
            D = new int[n];
            P = new int [n];
            H = new priority_queue<int, int, int>[n];
        }

        ~Graph(){
            delete [] D;
            delete [] P;
            delete [] Mark;
        }

        int countNode;
        int *D;
        int *P;
        bool *Mark;
        priority_queue<int, int, int> *H;

        void setMark(int v, bool var){
            Mark[v] = var;
        }        
};

void Dijkstra(Graph G, int s){
    for(int i = 0; i < G.countNode; i++){
        G.D[i] = G.countNode + 1;
        G.P[i] = -1;

        G.setMark(i, false);
    }
    G.H[1] = {s, s, 0};
    G.D[s] = 0;
    for(int i = 0; i < G.countNode; i++){
        do{
            //p v aqui
            if()
        }while(!())
    }

}
int main(void){

    return 0;
}