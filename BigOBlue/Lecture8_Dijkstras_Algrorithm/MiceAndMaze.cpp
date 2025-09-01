#include<iostream>
#include<queue>
#include<vector>
#define MAX 105
const int INF = 1e9 + 7;
using namespace std;

vector<vector<pair<int, int>>> graph(MAX);
vector<int> dist(MAX, INF);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        for(pair<int, int> &neighbor : graph[u]) {
            if(w + neighbor.second <= dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push({neighbor.first, dist[neighbor.first]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, E, T, M;
    int u, v, w;
    cin >> N >> E >> T >> M;

    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[v].push_back({u, w});
    }

    Dijkstra(E);
    int count = 0;
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= T) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}