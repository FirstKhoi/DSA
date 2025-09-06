#include <iostream>
#include <map>
#include <queue>
#define MAX 2000
using namespace std;

vector<int> adj[MAX];
vector<int> dist(MAX, -1), visited(MAX, false);

void BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int &v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    int p = 1;
    map<string, int> m;
    for(int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;

        if(!m[a]) m[a] = p++;
        if(!m[b]) m[b] = p++;
        if(!m[c]) m[c] = p++;

        adj[m[a]].push_back(m[b]);
        adj[m[a]].push_back(m[c]);
        adj[m[b]].push_back(m[a]);
        adj[m[b]].push_back(m[c]);
        adj[m[c]].push_back(m[b]);
        adj[m[c]].push_back(m[a]);
    }
    
    if(m.find("Isenbaev") != m.end()) {
        BFS(m["Isenbaev"]);
    }
    
    for(auto it = m.begin(); it != m.end(); it++) {
        string name = it->first;
        
        if(visited[it->second]) {
            cout << name << " " << dist[it->second] << endl;
        } else cout << name << " undefined" << endl;
    }
    
    return 0;
}