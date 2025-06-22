#include<bits/stdc++.h>
#define MAX 100 + 5
using namespace std;
//https://bigocoder.com/courses/252/lectures/3824/problems/547?view=statement
int V, E;
    bool visited[MAX];
    int dist[MAX];
    vector<int> graph[MAX];
    
    void DFS(int scr) {
        stack<int> s;
        visited[scr] = true;
        dist[scr] = 0;
        s.push(scr);
        while(!s.empty()) {
            int u = s.top();
            s.pop();

            for(int v : graph[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    s.push(v);
                }
            }
        } 
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q, u, v;
    cin >> V;
    E = V - 1;

    for(int i = 1; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0, min_dist = MAX;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> u;
        if(dist[u] < min_dist || (dist[u] == min_dist && u < ans)) {
            min_dist = dist[u];
            ans = u;
        }
    }
    
    cout << ans;
    return 0;
}