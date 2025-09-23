#include <iostream>
#include <queue>
#define MAX 1005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist, parent;
vector<bool> visited;

void Prim(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        visited[u] = true;

        for(auto &edge : graph[u]) {
            int v = edge.second;
            int w = edge.first;
            if(!visited[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
}

int main() {
    int T, p, n, m, u, v, w;
    cin >> T;

    while(T--) {
        cin >> p >> n >> m;

        dist.assign(n + 1, INF);
        visited.assign(n + 1, false);
        parent.assign(n + 1, -1);

        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        
        int s = 1;
        Prim(s);
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(parent[i] != -1) { 
                ans += dist[i];
            }
        }
        cout << ans * p << endl;
    }
    return 0;
}