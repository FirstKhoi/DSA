#include<iostream>
#include<vector>
#include<queue>
#define MAX 500 + 1
using namespace std;
const int INF = 1e9 + 7;
//https://bigocoder.com/courses/252/lectures/3826/problems/602?view=statement

vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if(dist[u] != w) {
            continue;
        }

        for(pair<int, int> &neighbor : graph[u]) {
            if(w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    int n, a, b, w;
    cin >> n;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int ,int>>());

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    int s, q, v;
    cin >> s;
    Dijkstra(s);
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> v;

        if(dist[v] != INF) {
            cout << dist[v] << endl;
        } else {
            cout << "NO PATH" << endl;
        }
    }
    return 0;
}