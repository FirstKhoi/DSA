#include <iostream>
#include <vector>
#include <queue>
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[105];

vector<int> Dijkstra(int s, int n) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(w > dist[u]) continue;

        for(auto &v : graph[u]) {
            if(w + v.first < dist[v.second]) {
                dist[v.second] = w + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }
    return dist;
}

int main() {
    int t, n, r, tc = 1;
    cin >> t;
    while(t--) {
        cin >> n >> r;

        for(int i = 0; i < 105; i++) {
            graph[i].clear();
        }

        for(int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back({1, v});
            graph[v].push_back({1, u});
        }

        int s, d;
        cin >> s >> d;
        vector<int> distS = Dijkstra(s, n);
        vector<int> distD = Dijkstra(d, n);

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, distS[i] + distD[i]);
        }
        cout << "Case " << tc++ << ": " << res << endl;
    }
}