#include<iostream>
#include<stack>
#include<vector>
#define MAX 10000 + 5
using namespace std;

int N, M;
int visited[MAX];
vector<int> graph[MAX];

bool DFS(int src) {
    visited[src] = 1;

    for(int &v : graph[src]) {
        if(visited[v] == 1) {
            return true;
        } else if(visited[v] == 0) {
            if(DFS(v)) {
                return true;
            }
        }
    }
    visited[src] = 2;
    return false;
}

int main() {
    int t, u, v;
    cin >> t;
    while(t--) {
        cin >> N >> M;

        for(int i = 1; i <= N; i++) {
            graph[i].clear();
            visited[i] = 0;
        }

        for(int i = 0; i < M; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }

        bool isCyclic = false;

        for(int i = 1; i <= N; i++) {
            if(visited[i] == 0) {
                isCyclic = DFS(i);
                if(isCyclic) {
                    break;
                }
            }
        }
        cout << (isCyclic ? "YES" : "NO") << endl;
    }
    return 0;
}