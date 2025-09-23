#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree, ranks;

vector<int> topoSort(int n) {
    priority_queue<int, vector<int>, greater<int>> zeroIndegree;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            zeroIndegree.push(i);
        }
    }

    vector<int> ans;    
    while(!zeroIndegree.empty()) {
        int u = zeroIndegree.top();
        zeroIndegree.pop();
        ans.push_back(u);

        for(int &v : graph[u]) {
            indegree[v]--;
            ranks[v] = max(ranks[v], ranks[u] + 1);
            if(indegree[v] == 0) {
                zeroIndegree.push(v);
            }
        }
    }
    return ans;
}

int main() {
    int T, N, R, u, v;        
    int tc = 1;
    cin >> T;
    while(T--) {

        cin >> N >> R;
        graph.assign(N, {});
        indegree.assign(N, 0);
        ranks.assign(N, 1);

        for(int i = 0; i < R; i++) {
            cin >> v >> u;
            graph[u].push_back(v);
            indegree[v]++;
        }

        vector<int> res = topoSort(N);
        vector<pair<int, int>> tmp;

        for(int i = 0; i < N; i++) {
            tmp.push_back({ranks[i], i});
        }
        sort(tmp.begin(), tmp.end());
        cout << "Scenario #" << tc++ << ": " << endl;
        for(auto x : tmp) {
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}