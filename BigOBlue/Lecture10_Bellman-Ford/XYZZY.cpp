#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int MAXN = 105;

struct Edge {
    int to;
};

int n;
int energy[MAXN];
vector<Edge> adj[MAXN];

bool reachable(int from, int to) {
    queue<int> q;
    bool visited[MAXN] = {0};
    q.push(from);
    visited[from] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == to) return true;
        for (auto &e : adj[u]) {
            if (!visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }
    return false;
}

bool bellman_ford() {
    int dist[MAXN];
    for (int i = 1; i <= n; ++i) dist[i] = -INF;
    dist[1] = 100;
    for (int k = 1; k < n; ++k) {
        for (int u = 1; u <= n; ++u) {
            if (dist[u] > 0) {
                for (auto &e : adj[u]) {
                    int v = e.to;
                    if (dist[u] + energy[v] > dist[v]) {
                        dist[v] = dist[u] + energy[v];
                    }
                }
            }
        }
    }

    if (dist[n] > 0) return true;

    
    for (int u = 1; u <= n; ++u) {
        if (dist[u] > 0) {
            for (auto &e : adj[u]) {
                int v = e.to;
                if (dist[u] + energy[v] > dist[v]) {
                    if (reachable(v, n)) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    while (cin >> n && n != -1) {
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i <= n; ++i) {
            int m, x;
            cin >> energy[i] >> m;
            for (int j = 0; j < m; ++j) {
                cin >> x;
                adj[i].push_back({x});
            }
        }
        if (bellman_ford()) cout << "winnable\n";
        else cout << "hopeless\n";
    }
    return 0;
}

