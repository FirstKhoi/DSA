//https://codeforces.com/problemset/problem/1106/D
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
vector<bool> visited(MAX);

void minHeap(int s) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(s);
    visited[s] = true;
    
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        cout << u << " ";
        
        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                pq.push(v);
            }
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    minHeap(1);
    return 0;
}