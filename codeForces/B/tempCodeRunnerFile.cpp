#include <iostream>
#include <vector>
#include <queue>
#define MAX 20005
using namespace std;

int n, m;
vector<int> adj[MAX];
vector<bool> visited(MAX);
vector<int> dist(MAX);

void bfs(int s) {
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int &v : adj[u]) {
            if(!visited[v]) {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < MAX; i++) {
        if (i > 0) adj[i].push_back(i - 1);
        if (i * 2 < MAX) adj[i].push_back(i * 2);
    }

    bfs(n);
    cout << dist[m];
    return 0;
}