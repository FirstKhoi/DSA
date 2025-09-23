#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 105
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX], mstGraph[MAX];
vector<int> dist, parent;
vector<bool> visited;

void Prim(int s, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for(auto &edge : graph[u]) {
            int v = edge.second;
            int w = edge.first;
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
    
    for(int u = 1; u <= N; u++) {
        if(parent[u] != -1) {
            int v = parent[u], w = dist[u];
            mstGraph[u].push_back({w, v});
            mstGraph[v].push_back({w, u});
        }
    }
}

int dfs(int s, int f, int level) {
    if(s == f) return level;
    visited[s] = true;

    for(auto &edge : mstGraph[s]) {
        int v = edge.second;
        int w = edge.first;

        if(!visited[v]){ 
            int tmpLevel = dfs(v, f, max(level, w));
            if(tmpLevel != INF) return tmpLevel;
        }
    }
    return INF;
}

int main() {
    int N, M, Q, u, v, w, tc = 1;
    while(true) {
        cin >> N >> M >> Q;
        if(N == 0 && M == 0 && Q == 0) break;

        dist.assign(N + 1, INF);
        visited.assign(N + 1, false);
        parent.assign(N + 1, -1);
    
        for(int i = 1; i <= N; i++) {
            graph[i].clear();
            mstGraph[i].clear();
        }

        for(int i = 0; i < M; i++) {
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }

        vector<bool> prim_visited(N + 1, false);
        for(int i = 1; i <= N; i++) {
            if(!prim_visited[i]) {
                visited.assign(N + 1, false);
                Prim(i, N); 
                for(int j = 1; j <= N; j++) 
                    if (visited[j]) prim_visited[j] = true;
            }
        }
        
        if (tc != 1) cout << endl;
        cout << "Case #" << tc++ << "\n";

        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            visited.assign(N + 1, false);
            int level = dfs(u, v, 0);
            if (level != INF)
                cout << level << "\n";
            else
                cout << "no path\n";
        }
    }           
    return 0;   
}