#include <iostream>
#include <vector>
#include <queue>
const int INF = 1e9 + 7;
#define MAX 505
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void Dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (dist[u] < w)
            continue;

        for (auto &v : graph[u])
        {
            if (w + v.first < dist[v.second])
            {
                dist[v.second] = w + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }
}

int main()
{
    int n, a, b, u, v, w, q;
    cin >> n;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    dist.assign(MAX, INF);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    cin >> u;
    Dijkstra(u);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> v;
        if (dist[v] != INF)
            cout << dist[v] << endl;
        else
            cout << "NO PATH" << endl;
    }
    return 0;
}