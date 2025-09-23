#include <iostream>
#include <queue>
#include <vector>
#define MAX 3005
const int INF = 1e9 + 7;
using namespace std;

int N, M;
vector<pair<int, int>> graph[MAX], mstGraph[MAX];
vector<int> dist, parent;
vector<bool> visited;

void prim(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
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
}



int main() {
    cin >> N >> M;

    dist.assign(N + 1, INF);
    visited.assign(N + 1, false);
    parent.assign(N + 1, -1);

    for(int i = 1; i <=N; i++) {
        graph[i].clear();
    }

    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int S; cin >> S;
    prim(S);

    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        if(parent[i] != -1)
            ans += dist[i];
    }
    cout << ans;
    return 0;
}