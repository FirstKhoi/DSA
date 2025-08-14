#include<iostream>
#include<vector>
#define MAX_V 1005
#define MAX_E 2005
const int INF = 1e9;
using namespace std;
//https://bigocoder.com/courses/252/lectures/3842/problems/793?view=statement

struct Edge {
    int source, target, weight;
};

int n, m;
int dist[MAX_V];
Edge graph[MAX_E];

bool BMF(int s) {
    fill(dist, dist + n, INF);
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

    for(int j = 0; j < m; j++) {
        int u = graph[j].source;
        int v = graph[j].target;
        int w = graph[j].weight;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            return true;
        }
    }
    return false;
}
int main() {
    int T, x, y, t;
    cin >> T;
    
    while(T--) {
        cin >> n >> m;

        for(int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            graph[i] = (Edge) {x, y, t};
        }
    cout << (!BMF(0) ? "possible" : "not possible") << endl; cout << "not possible";
    }
    return 0;
}