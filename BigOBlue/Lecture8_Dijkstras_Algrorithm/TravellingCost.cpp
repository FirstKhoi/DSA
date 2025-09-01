#include<iostream>
#include<queue>
#define MAX 500 + 5
using namespace std;
const int INF = 1e9 + 7;

vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    int N, A, B, W;
    cin >> N;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());

    for (int i = 0; i < N; i++) {
        cin >> A >> B >> W;
        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }

    int S, Q, V;
    cin >> S;
    Dijkstra(S);
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> V;
        
        if (dist[V] != INF) {
            cout << dist[V] << endl;
        }
        else {
            cout << "NO PATH" << endl;
        }
    }

    return 0;
}