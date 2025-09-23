#include <iostream>
#include <vector>
#include <queue>
#define MAX 100005
const int INF = 1e9 + 7;
using namespace std;

vector<pair<int, int>> graph[MAX];

vector<int> Dijkstra(int s) {
	vector<int> dist(MAX, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	dist[s] = 0;

	while(!pq.empty()) {
		pair<int, int> top = pq.top(); pq.pop();
		int u = top.second;
		int w = top.first;

		if(w != dist[u]) continue;

		for(auto &v : graph[u]) {
			if(w + v.first < dist[v.second]) {
				dist[v.second] = w + v.first;
				pq.push({dist[v.second], v.second});
			}
		}
	}
	return dist;
}

int main() {
	int N, M, k, x, u, v, w, A, B;
	cin >> N >> M >> k >> x;
	
	vector<int> cities(k);
	for(int i = 0; i < k; i++) {
		cin >> cities[i];
	}

	for(int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}
		cin >> A >> B;
		vector<int> distA = Dijkstra(A);
		vector<int> distB = Dijkstra(B);
		int res = INF;

		for(int &city : cities) {
			if(distB[city] <= x) {
				res = min(res, distA[city] + distB[city]);
			}
		}
		cout << (res < INF ? res : -1) << endl;
	return 0;
}