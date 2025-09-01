#include<iostream>
#include<vector>
#define MAXN 105
#define MAXM 1005
const int INF = 1e9 + 7;
using namespace std;

struct Edge {
    int source, target, weight;
};

int n, m;
vector<int> dist(MAXN, INF);
vector<Edge> graph(MAXM);

bool BellmanFord(int s) {
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T, u, v, w;
    cin >> T;
    while(T--) {
        cin >> n >> m;

        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[i] = (Edge) {u, v, -w};
        }
        if(BellmanFord(1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}