#include<iostream>
#include<queue>
#include<cassert>
#define MAX 10005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];

void Dijkstra(int s, int dist[], vector<pair<int, int>> (&graph)[MAX]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        if(w > dist[u]) continue;

        for(pair<int, int> &neighbor : graph[u]) {
            if(w + neighbor.second <= dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push({neighbor.first, dist[neighbor.first]});
            }
        }
    }
}



int main() {
    int T, n, m, k, s, t, u, v, d;
    cin >> T;
    assert(T >= 1 && T <= 20);
        while(T--) {
            cin >> n >> m >> k >> s >> t;
            
            for(int i = 1; i <= n; i++) {
                graphS[i].clear();
                graphT[i].clear();
                distS[i] = INF;
                distT[i] = INF;
            }

            for(int i = 0; i < m; i++) {
                cin >> u >> v >> d;
                graphS[u].push_back({v, d});
                graphT[v].push_back({u, d});
            }

            Dijkstra(s, distS, graphS);
            Dijkstra(t, distT, graphT);

            int res = distS[t];

            for(int i = 0; i < k; i++) {
                cin >> u >> v >> d;
                int a = distS[u] + d + distT[v];
                int b = distS[v] + d + distT[u];
                res = min(res, min(a, b));
            }

            if(res != INF) {
                cout << res << endl;
            } else cout << -1 << endl;
    }
    return 0;
}