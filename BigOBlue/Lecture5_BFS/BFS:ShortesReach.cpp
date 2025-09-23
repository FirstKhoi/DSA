#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[1005];
vector<bool> visited;
vector<int> dist;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }   
}

int main() {
    int q, n, m;
    cin >> q;

    while(q--) {
        cin >> n >> m;
        visited.assign(n + 1, false);
        dist.assign(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s;
        cin >> s;
        bfs(s);
        for(int i = 1; i <= n; i++) {
            if(i == s) continue;
            cout << (visited[i] ? dist[i] * 6 : -1) << " ";
        }
        cout << endl;
    }
    return 0;
}           