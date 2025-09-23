#include<iostream>
#include<vector>
#define MAX 105
const int INF = 1e9 + 7;
using namespace std;

struct Edge {
    int source, target, weight;
};

int n;
int dist[MAX];
vector<Edge> graph;

void BellmanFord(int s, int n) {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    for(int i = 0; i < n -1; i++) {
        for(auto &edge : graph) {
            int u = edge.source;
            int v = edge.target;
            int w = edge.weight;

            if(dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
}

int main() {
    int n; cin >> n;
    string temp;
    for(int i = 2; i <=n ; i++) {
        for(int j = 1; j < i; j++) {
            cin >> temp;

            if(temp != "x") {
                int w = stoi(temp);
                graph.push_back({i, j, w});
                graph.push_back({j, i, w});
            }
        }
    }
    BellmanFord(1, n);
    int res = 0;
    for(int i = 2; i <= n; i++) {
        res = max(res, dist[i]);
    }
    cout << res << endl;
    return 0;
}