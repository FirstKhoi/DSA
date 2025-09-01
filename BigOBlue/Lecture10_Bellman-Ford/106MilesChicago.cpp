#include<iostream>
#include<vector>
#include<iomanip>
#define MAX_V 105
#define MAX_E 105 * 5 + 5
const int INF = 1e9 + 7;
using namespace std;

struct Edge {
    int source, target;
    double weight;
};

int n, m;
vector<double> dist(MAX_V, -1.0);
vector<Edge> graph(MAX_E);

void BellmanFord() {
    dist[1] = 1.0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;

            dist[u] = max(dist[u], dist[v] * w);
            dist[v] = max(dist[v], dist[u] * w);
        }
    }
}

int main() {
    int u, v, c;
    while(cin >> n, n != 0) {
        cin >> m;

        for(int i = 0; i < m; i++) {
            cin >> u >> v >>c;
            graph[i] = (Edge) {u, v, c / 100.0};
        }

        BellmanFord();    
        cout << fixed << setprecision(6) << dist[n] * 100.0 << " percent" << endl;
    }

    return 0;   
}