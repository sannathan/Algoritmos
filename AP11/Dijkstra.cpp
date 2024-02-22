#include <iostream>
#include <queue>

using namespace std;

class Graph{
    public:
        Graph (int n){
            //D = new int[n];
            P = new int [n];
            H = new priority_queue<int, int, int>[n];
            Mark = new bool [n];
            matrix = new int*[n];
            for(int i{}; i < n; i++){
                matrix[i] = new int[n];
            }
        }

        ~Graph(){
            //delete [] D;
            delete [] P;
            delete [] Mark;
        }

        int countNode;
        //int *D;
        int *P;
        int **matrix;
        bool *Mark;
        priority_queue<int, int, int> *H;

        void setMark(int v, bool var){
            Mark[v] = var;
        }

        bool GetMark(int v){
            return Mark[v];
        }

        int next(int v, int w){
            for(int i = w + 1; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
        }

        int first(int v){
            for(int i{}; i <= countNode - 1; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            return countNode;
        }

        void Dijkstra(int s, int *D){
            int v, p, w;
            for(int i = 0; i < countNode; i++){
                D[i] = countNode + 1;
                P[i] = -1;

                setMark(i, false);
            }
            H[1].emplace(s, s, 0);
            D[s] = 0;
            for(int i = 0; i < countNode; i++){
                do{
                    H[1].pop(p, v);
                    if()
                }while(!(GetMark(v) == false));
                setMark(v, true);
                P[v] = p;
                w = first(v);
                while(w < countNode){
                    if(GetMark(w) != true && D[w] > (D[v] + weight(v, w)){
                        D[w] = D[v] + weight(v, w);
                        in
                    }
                    w = next(v, w);
                }
            } 
        }       
};

int main(void){

    return 0;
}