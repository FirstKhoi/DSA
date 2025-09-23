#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100005
const int INF = 1e9 + 7;

int N, M, Q;
vector<int> a;
vector<pair<int, int>> graph[MAX];
vector<int> dist, parent;
vector<bool> visited;

void Prim(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        visited[u] = true;

        for(auto &edge : graph[u]) {
            int v = edge.second;
            int w= edge.first;
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }   
}

int main() {
    cin >> N >> M;
    int A, B, L;

    dist.assign(N + 1, INF);
    visited.assign(N + 1, false);
    parent.assign(N + 1, -1);

    for(int i = 1; i <= N; i++) {
        graph[i].clear();
    }

    for(int i = 0; i < M; i++) {
        cin >> A >> B >> L;
        graph[A].push_back({L, B});
        graph[B].push_back({L, A});
    }

    Prim(1);
    priority_queue<int> Cable;
    for(int i = 2; i <= N; i++) {
        Cable.push(dist[i]);
    }

    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> newCables;
    int x;
    for(int i = 0; i < Q; i++) {
        cin >> x;
        newCables.push(x);
    }   

    long long ans = 0;
    while(!Cable.empty()) {
        int replacedCable = Cable.top(); Cable.pop();
        if(!newCables.empty() && newCables.top() < replacedCable) {
            replacedCable = newCables.top();
            newCables.pop();
        }
        ans += replacedCable;
    }
    cout << ans << endl;
    return 0;

}