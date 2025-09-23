#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1e9 + 7;

struct Edge
{
    int source, target, weight;
};

int n, m;
vector<Edge> graph;
vector<int> dist;
vector<bool> hasNegCycle;
vector<int> weight;

void BellmanFord(int s)
{
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        int u = graph[j].source;
        int v = graph[j].target;
        int w = graph[j].weight;
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            hasNegCycle[v] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = graph[j].source;
            int v = graph[j].target;
            if (hasNegCycle[u])
            {
                hasNegCycle[v] = true;
            }
        }
    }
}

int main()
{
    int T, q, u, v, f, tc = 1;
    cin >> T;
    while (T--)
    {
        cin >> n;
        dist.assign(n + 1, INF);
        hasNegCycle.assign(n + 1, false);
        weight.assign(n + 1, 0);
        graph.clear();

        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            int edgeWeight = pow(weight[v] - weight[u], 3);
            graph.push_back({u, v, edgeWeight});
        }

        BellmanFord(1);
        cin >> q;
        cout << "Case " << tc++ << ":" << endl;

        for (int i = 0; i < q; i++)
        {
            cin >> f;
            if (hasNegCycle[f] || dist[f] == INF || dist[f] < 3)
            {
                cout << "?" << endl;
            }
            else
            {
                cout << dist[f] << endl;
            }
        }
    }
    return 0;
}
