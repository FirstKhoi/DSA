#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string topoSort(const vector<vector<int>>& graph, const vector<int>& indegree) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> deg = indegree; 
    string order;

    for (int i = 0; i < 26; ++i)
        if (deg[i] == 0) pq.push(i);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        order += (char)('a' + u);
        for (int v : graph[u]) {
            deg[v]--;
            if (deg[v] == 0) pq.push(v);
        }
    }
    if (order.size() < 26) return "";
    return order;
}

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (auto &x : names) cin >> x;
    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0);

    for (int i = 0; i + 1 < n; ++i) {
        string &a = names[i], &b = names[i+1];
        int len = min(a.size(), b.size());
        bool found = false;
        for (int j = 0; j < len; ++j) {
            if (a[j] != b[j]) {
                graph[a[j] - 'a'].push_back(b[j] - 'a');
                indegree[b[j] - 'a']++;
                found = true;
                break;
            }
        }
        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    string order = topoSort(graph, indegree);
    if (order == "") cout << "Impossible\n";
    else cout << order << "\n";
}