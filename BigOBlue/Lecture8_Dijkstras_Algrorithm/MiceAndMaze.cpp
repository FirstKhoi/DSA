#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[105];
vector<int> dist(105, INT_MAX);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();
        int w = top.first;
        int u = top.second;


        if(w > dist[u]) continue;

        for(auto &neighbor : graph[u]) {
            if(w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push({dist[neighbor.second], neighbor.second});
            }
        }
    }
}

int main() {
    int n, e, t, m, u, v, w;
    cin >> n >> e >> t >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[v].push_back({w, u});
    }

    Dijkstra(e);

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] <= t) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}