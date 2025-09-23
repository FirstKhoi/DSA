#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, m;
struct Edge {
    int source, target;
    double weight;
};

vector<Edge> graph;
vector<double> dist;

void BellmanFord(int s) {
    fill(dist.begin(), dist.end(), 0.0);
    dist[s] = 1.0;   

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;
            
            if(dist[u] * w > dist[v]) {
                dist[v] = dist[u] * w;
            }
            if(dist[v] * w > dist[u]) {
                dist[u] = dist[v] * w;
            }
        }
    }
}

int main() {
    int u, v, w;
    
    while(cin >> n, n != 0) {
        cin >> m;
        graph.assign(m, {});
        dist.assign(n + 1, 0.0);
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[i] = (Edge) {u, v, w / 100.0};
        }

        BellmanFord(1);

        cout << fixed << setprecision(6) << dist[n] * 100.0 << " percent" << endl;
    }
    return 0;
}