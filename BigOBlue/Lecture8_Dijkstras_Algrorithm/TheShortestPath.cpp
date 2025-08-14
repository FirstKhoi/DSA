#include<iostream>
#include<queue>
using namespace std;
const int INF = 1e7 + 9;
#define MAX 10000 + 5
//https://bigocoder.com/courses/252/lectures/3826/problems/604?view=statement

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;

int City(string name) {
    for(int i = 0; i < cities.size(); i++) {
        if(name == cities[i]) {
            return i;
        }
    }
    return -1;
}

void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    
    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;
        
        if(dist[u] == w) {
            continue;
        }

        for(pair<int, int> &neighbor : graph[u]) {
            if(w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }
}

int main() {
    int t, n, q;
    int neighbors, u, v, w;
    string name, sCity, fCity;
    cin >> t;

    while(t--) {
        cin >> n;

        for(int i = 1; i < n; i++) {
            graph[i].clear();
        }
        cities.clear();

        for(int u = 1; u < n; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);
        }

        for(int i = 0; i < neighbors; i++) {
            cin >> v >> w;
            graph[u].push_back(make_pair(w, v));
        }

        cin >> q;
        for(int i = 0; i < q; i++) {
            cin >> sCity >> fCity;
            int s = City(sCity) + 1;
            int f = City(fCity) + 1;
            dist = vector<int>(n + 1, INF);
            Dijkstra(s, f);
            cout << dist[f] << endl;
        }
    }
    return 0;
}