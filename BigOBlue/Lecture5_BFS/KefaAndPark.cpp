#include <iostream>
#include <queue>
#include <vector>
#define MAX 100005
using namespace std;


vector<int> graph[MAX];
vector<int> cats(MAX);
vector<bool> visited(MAX);
int maxCats;

int BFS(int s) {
    int restaurants = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        
        bool isLeaf = true;
        for(int &v : graph[u]) {
            if(!visited[v]) {
                isLeaf = false;
                visited[v] = true;
                
                if(cats[v] == 1) {
                    cats[v] = cats[u] + 1;
                } else {
                    cats[v] = 0;
                }
                
                if(cats[v] <= maxCats) {
                    q.push(v);
                }
            }
        }
        
        if(isLeaf && u != 1) {
            restaurants++;
        }
    }
    return restaurants;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    maxCats = m;
    
    for(int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << BFS(1) << endl;
    return 0;
}