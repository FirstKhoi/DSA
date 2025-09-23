#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
const int INF = 1e9 + 7;
#define MAX 751
using namespace std;

int N, M;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX), parent(MAX);
vector<bool> visited(MAX);
int x[MAX], y[MAX];

int distance(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

double result() {
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += sqrt(dist[i]);
        if (ans >= INF) {
            return -1;
        }
    }
    return ans;
}

void Prim(int s) {
    fill(dist.begin(), dist.end(), INF);
    fill(parent.begin(), parent.end(), -1);
    fill(visited.begin(), visited.end(), false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();
        visited[u] = true;

        for(pair<int, int> &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!visited[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
}

int main() {
    while (cin >> N) {
        for(int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
            graph[i].clear();
        }
        
        cin >> M;
        vector<vector<bool>> edges(MAX, vector<bool>(MAX, false));
        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            edges[a-1][b-1] = true;
            edges[b-1][a-1] = true;
        }
        
        for(int i = 0; i < N-1; i++) {
            for(int j = i+1; j < N; j++) {
                if(edges[i][j] == false) {
                    int w = distance(i, j);
                    graph[i].push_back({j, w});
                    graph[j].push_back({i, w});
                } else {
                    graph[i].push_back({j, 0});
                    graph[j].push_back({i, 0});
                }
            }
        }
        
        Prim(0);
        double r = result();
        cout << fixed << setprecision(2) << r << endl;
    }
    return 0;
}