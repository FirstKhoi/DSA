#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> graph[105];
vector<int> dist(105, INT_MAX);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;

        for(auto &neighbor : graph[u]) {
            if(w + neighbor.first < dist[u]) {
                dist[u] = w + neighbor.first;
                pq.push({dist[u], neighbor.second});
            }
        }
    }
}

int main() {
    int n, e, t, m, u, v, w;
    cin >> n;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[v].push_back({w, u});
    }

    Dijkstra(e);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] <= t) {
            count++;
        }
    }
    cout << count;
    return 0;
}