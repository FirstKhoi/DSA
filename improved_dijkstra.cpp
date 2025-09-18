#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    vector<int> distance(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (distance[node] + edgeWeight < distance[nextNode]) {
                distance[nextNode] = distance[node] + edgeWeight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
    return distance;
}

int main() {
    int vertices = 5; // Example: 5 vertices
    vector<vector<pair<int, int>>> graph(vertices);
    
    // Add edges (example)
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 3);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 2);
    graph[2].emplace_back(1, 4);
    graph[2].emplace_back(3, 8);
    graph[2].emplace_back(4, 2);
    graph[3].emplace_back(4, 7);
    graph[4].emplace_back(3, 9);

    vector<int> distances = dijkstra(0, graph);
    
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from node 0 to node " << i << " is " << distances[i] << endl;
    }

    return 0;
}