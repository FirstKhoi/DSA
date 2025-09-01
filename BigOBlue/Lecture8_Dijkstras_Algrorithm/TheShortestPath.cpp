#include<iostream>
#include<queue>
#define MAX 10005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;

int Name(string name) {
    for(int i = 0; i < cities.size(); i++) {
        if(name == cities[i]) {
            return i;
        }
    }
    return -1;
}

void Dijkstra(int s, int e) {
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
    int T, N, Q;
    int neighbors, u, v, w;
    string name, sCity, eCity;
    cin >> T;

    while(T--) {
        cin >> N;

        for(int i = 1; i <= N; i++) {
            graph[i].clear();
        }
    
        cities.clear();
    
        for(int u = 1; u <= N; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);
            
            for(int i = 0; i < neighbors; i++) {
                cin >> v >> w;
                graph[u].push_back({v, w});
            }
        }

        cin >> Q;
        for(int i = 0; i < Q; i++) {
            cin >> sCity >> eCity;
            int s = Name(sCity) + 1;
            int e = Name(eCity) + 1;
            dist = vector<int>(N + 1, INF);
            Dijkstra(s, e);
            cout << dist[e] << endl;
        }

    }

    return 0;
}