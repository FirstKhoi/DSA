#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> visited(7);
vector<int> graph[7];

void BFS(int s, vector<int>& component) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    component.push_back(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                component.push_back(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    vector<vector<int>> components;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            vector<int> component;
            BFS(i, component);
            components.push_back(component);
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto &comp : components) {
        for(int x : comp) cout << x << " ";
        cout << endl;
    }
}
