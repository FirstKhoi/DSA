#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> graph[501];
vector<int> dist(501, INT_MAX);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int w = top.first;
        int u = top.second;

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
    int N, A, B, W;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A >> B >> W;
        graph[A].push_back({W, B});
        graph[B].push_back({W, A});
    }

    int U, Q, V;
    cin >> U;
    Dijkstra(U);
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> V;
        if(dist[V] != INT_MAX) {
            cout << dist[V] << endl;
        } else cout << "NO PATH" << endl;
    }
    return 0;
}