#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define MAX 105
const double INF = 1e9 + 7;
using namespace std;

vector<pair<double, int>> graph[MAX];
vector<double> dist, parent;
vector<bool> visited;

struct Point {
    double x, y;
};

double w(const Point &a, const Point &b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void prim(int s) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(visited[u]) continue;
        visited[u] = true;

        for(auto &edge : graph[u]) {
            int v = edge.second;
            double w = edge.first;
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
}

int main() {
    int t; cin >> t;
    string line; getline(cin, line);

    for(int tc = 0; tc < t; tc++) {
        while(getline(cin, line) && line.empty());
        int n = stoi(line);
        vector<Point> points(n);
        for(int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        for(int i = 0; i < n; i++) graph[i].clear();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double weight = w(points[i], points[j]);
                graph[i].push_back({weight, j});
                graph[j].push_back({weight, i});
            }
        }
    
        dist.assign(n, INF);
        parent.assign(n, -1);
        visited.assign(n, false);
    
        prim(0);
    
        double total = 0.0;
        for(int i = 0; i < n; i++) {
            total += dist[i];
        }
        cout.precision(2);
        cout << fixed << total << endl;
        if(tc != t - 1) cout << endl;
    }
    return 0;
}