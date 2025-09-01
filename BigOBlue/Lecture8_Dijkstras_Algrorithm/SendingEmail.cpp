#include<iostream>
#include<queue>
#define MAX 20005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);

void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        if(dist[u] != w) continue;

        for(pair<int, int> &neighbor : graph[u]) {
            if(w + neighbor.second <= dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push({neighbor.first, dist[neighbor.first]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, n, m, s, t;
    int u, v, w;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> n >> m >> s >> t;
        if(n < 2 || n > 20000) return N;
        else if(m < 0 || m > 50000) return N;
        else if(s < 0 || s >= n) return N;
        else if(t < 0 || t >= n) return N;

        for(int i = 0; i < n; i++) {
            graph[i].clear();
            dist[i] = INF;
        }

        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            if(u < 0 || u > n) return N;
            else if(v < 0 || v > n) return N;
            else if(w < 0 || w > n) return N;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        Dijkstra(s, t);

        cout << "Case #" << t << ": ";

        if(dist[t] != INF) {
            cout << dist[t] << endl;
        } else {
            cout << "unreachable" << endl;
        }
    }
    return 0;
}