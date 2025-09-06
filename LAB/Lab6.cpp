#include<iostream>
#include<vector>
#include<queue>
#define MAX 11
using namespace std;

vector<bool> visited(MAX, false);
vector<int> graph[MAX];

void BFS(int s) {
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
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

    BFS(1);
    bool check = true;
    for(int i = 1; i <=n ; i++) {
        if(!visited[i]) {
            bool check = false;
            break;
        }
    }

    if(check) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}