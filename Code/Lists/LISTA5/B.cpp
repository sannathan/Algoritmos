#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Graph{
    public:
        Graph (int n){
            Mark = new bool[n];
            numEdge = 0;
            countNode = n;
        }

        map<string, vector<string>> adj;
        map<string, int> dist;
        set<string> all_nodes;
        
        void setEdge(string i, string j){
            adj[i].push_back(j);
        }

        void BFS(string start){
            queue<string> Q;
            Q.push(start);
            dist[start] = 0;
            
            while(Q.size() > 0){
                string v = Q.front();
                Q.pop();
                
                for(string child : adj[v]){
                    if(dist.count(child) == 0){
                        dist[child] = dist[v] + 1;
                        Q.push(child);
                    }
                }
            }  
        }

    private:
        int numEdge;
        bool *Mark;
        int countNode;
};

int main(void){
    int T;

    cin >> T;

    for(int i{}; i < T; i++){
        int N;

        cin >> N;
        
        Graph equipes(N);
        equipes.adj.clear();
        equipes.dist.clear();
        equipes.all_nodes.clear();

        for(int j{}; j < N; j++){
            string n1, n2, n3;

            cin >> n1 >> n2 >> n3;
            equipes.all_nodes.insert(n1);
            equipes.all_nodes.insert(n2);
            equipes.all_nodes.insert(n3);
            equipes.setEdge(n1,n2);
            equipes.setEdge(n1,n3);
            equipes.setEdge(n2,n1);
            equipes.setEdge(n2,n3);
            equipes.setEdge(n3,n1);
            equipes.setEdge(n3,n2);
        }
        equipes.BFS("Ahmad");

        vector<pair<int, string>> ans;
        for(auto it : equipes.dist){
            ans.push_back({it.second, it.first});
        }
        for(auto it : equipes.all_nodes){
            if(equipes.dist.count(it) == 0){
                ans.push_back({INT_MAX, it});
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;

        for(auto it : ans){
            if(it.first == INT_MAX){
                cout << it.second << " " << "undefined" << endl;
            }
            else{
                cout << it.second << " " << it.first << endl;
            }
        }

        
    }
    

    return 0;
}