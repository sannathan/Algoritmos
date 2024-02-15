#include<bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;
map<string, int> dist;
set<string> all_nodes;

void bfs(string src) {
    queue<string> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        string node = q.front();
        q.pop();
        for(string child : adj[node]) {
            if(dist.count(child) == 0) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        adj.clear();
        dist.clear();
        all_nodes.clear();
        for(int i = 0; i < n; i++) {
            string a, b, c;
            cin >> a >> b >> c;
            all_nodes.insert(a);
            all_nodes.insert(b);
            all_nodes.insert(c);
            adj[a].push_back(b);
            adj[a].push_back(c);
            adj[b].push_back(a);
            adj[b].push_back(c);
            adj[c].push_back(a);
            adj[c].push_back(b);
        }
        bfs("Ahmad");
        vector<pair<int, string>> ans;
        for(auto it : dist) {
            ans.push_back({it.second, it.first});
        }
        for(auto it : all_nodes) {
            if(dist.count(it) == 0) {
                ans.push_back({INT_MAX, it});
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto it : ans) {
            if(it.first == INT_MAX) {
                cout << it.second << " " << "indefinido" << "\n";
            } else {
                cout << it.second << " " << it.first << "\n";
            }
        }
    }
    return 0;
}
