#include <iostream>
#include <vector>
#include <queue>
#include <map>
const int INF = 1e9 + 7;
#define MAX 205
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dist, parent;
vector<bool> visited; 

map<string, int> cityIndex;
int idx = 1;

int getCityIndex(const string &city) {
    if(cityIndex.find(city) == cityIndex.end()) {
        cityIndex[city] = idx++;
    }
    return cityIndex[city];
}

void Prim(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        visited[u] = true;
        pq.pop();

        for(auto &edge : graph[u]) {
            int v = edge.second;
            int w = edge.first; 
            if(!visited[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
}

int main() {

    int T, m, w, tc = 1;
    string sCity, fCity;
    
    cin >> T;
    while(T--) {
        cin >> m;
        cityIndex.clear();
        idx = 1;
        
        for(int i = 0; i < MAX; i++) {
            graph[i].clear();
        }
        dist.clear();
        visited.clear();
        parent.clear();
        
        for(int i = 0; i < m; i++) {
            cin >> sCity >> fCity;
            int u = getCityIndex(sCity);
            int v = getCityIndex(fCity);

            cin >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        
        int n = idx - 1; 
        dist.assign(n + 1, INF);
        visited.assign(n + 1, false);
        parent.assign(n + 1, -1);

        long long ans = 0;
        Prim(1);
        
        bool impossible = false;
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                impossible = true;
                break;
            }
            if(i != 1) {
                ans += dist[i];
            }
        }
        
        if(impossible) {
            cout << "Case " << tc++ << ": Impossible" << endl;
        } else {
            cout << "Case " << tc++ << ": " << ans << endl;
        }
    }
    return 0;
}