//https://codeforces.com/problemset/problem/506/D
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100005;

map<pair<int, int>, int> query_cache;

bool isConnected(int u, int v, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == v) return true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> edges_by_color;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges_by_color[c].push_back({u, v});
    }
    
    map<int, vector<vector<int>>> adj_by_color;
    for(auto &color_edges : edges_by_color) {
        int color = color_edges.first;
        vector<pair<int, int>> &edges = color_edges.second;
        
        vector<vector<int>> adj(n + 1);
        for(auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        adj_by_color[color] = adj;
    }

    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        if(u > v) swap(u, v);
        pair<int, int> query = {u, v};
        
        if(query_cache.count(query)) {
            cout << query_cache[query] << "\n";
            continue;
        }
        
        int count = 0;
        for(auto &color_adj : adj_by_color) {
            int color = color_adj.first;
            const vector<vector<int>>& adj = color_adj.second;
            
            if(isConnected(u, v, adj)) {
                count++;
            }
        }
        
        query_cache[query] = count;
        cout << count << "\n";
    }
    
    return 0;
}