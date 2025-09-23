#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

vector<int> topological(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) pq.push(i);
    }
    
    vector<int> res;
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        res.push_back(u);

        for(int &v : graph[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.assign(n + 1, vector<int>()); 
    indegree.assign(n + 1, 0);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    vector<int> result = topological(n);
    if(result.size() != n) cout << "Sandro fails." << endl;
    else {
        for(int i = 0; i < n; i++) {
            cout << result[i];
            if(i < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}