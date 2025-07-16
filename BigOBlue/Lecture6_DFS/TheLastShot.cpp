#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#define MAX 10000 + 5
using namespace std;

int n, m;
bool visited[MAX];
vector<int> graph[MAX];

int DFS(int src) {
    memset(visited, false, sizeof(visited));
    stack<int> s;
    visited[src] = true;
    s.push(src);

    int boms = 0;
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        boms++;

        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    return boms;
}

int main() {
    int u, v;
    cin >> n >> m;

    for(int i =0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int maxBoms = 0;
    for(int i = 1; i <= n; i++) {
        maxBoms = max(maxBoms, DFS(i));
    }
    cout << maxBoms << endl;
    return 0;
}