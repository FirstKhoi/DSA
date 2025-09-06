#include<iostream>
#include<queue>
#include<vector>
#define MAX 1005
using namespace std;

vector<int> graph[MAX];
vector<bool> visited(MAX, false);
vector<int> parent(MAX, -1);

void BFS(int s, int f) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int &v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);

                if (v == f) return; 
            }
        }
    }
}

void printPath(int s, int f) {
    vector<int> path;
    int curr = f;
    while (curr != -1) {
        path.push_back(curr);
        if (curr == s) break;
        curr = parent[curr];
    }

    if (path.back() != s) {
        cout << "No path" << endl;
        return;
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m, u, v, s, f;
    cin >> n >> m >> s >> f;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    BFS(s, f);
    printPath(s, f);

    return 0;
}
