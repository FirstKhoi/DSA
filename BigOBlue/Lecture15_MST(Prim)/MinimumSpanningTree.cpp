#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100005
const int INF = 1e9 + 7;

vector<pair<int, int>> graph[MAX];
vector<int> dist;
vector<bool> visited;
vector<int> parent;

void Prim(int s, int N) {
    fill(dist.begin(), dist.end(), INF);
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto &edge : graph[u]) {
            int v = edge.second;
            int w = edge.first;
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    dist.assign(N+1, INF);
    visited.assign(N+1, false);
    parent.assign(N+1, -1);

    int u, v, w;
    
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int s = 1;
    Prim(s, N+1);

    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        if(parent[i] == -1) continue;
        ans += dist[i];
    }
    cout << ans << endl;
    return 0;
}