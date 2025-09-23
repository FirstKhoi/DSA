#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 10005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;

int Name(string name) {
    for(int i = 0; i < cities.size(); i++){
        if(name == cities[i]) {
            return i;
        }
    }
    return -1;
}

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.second;
        int w = top.first;

        if(w > dist[u]) continue;

        for(auto &neighbor : graph[u]) {
            if(w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push({dist[neighbor.second], neighbor.second});
            }
        }
    }
}

int main() {
    int t, n, q;
    int neighbors, u, v ,w;
    string name, sCity, fCity;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        cities.clear();

        for(int u = 1; u <= n; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);
            for(int i = 0; i < neighbors; i++) {
                cin >> v >> w;
                graph[u].push_back({w , v});
            }
        }
        cin >> q;
        for(int i = 0; i < q; i++) {
            cin >> sCity >> fCity;
            int s = Name(sCity) + 1;
            int f = Name(fCity) + 1;
            dist = vector<int>(MAX, INT_MAX);
            Dijkstra(s);
            cout << dist[f] << endl;
        }
    }
    return 0;
}