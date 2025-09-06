#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 11
using namespace std;

vector<int> graph[MAX];
vector<bool> visited(MAX);

void DFS(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true; 

    while(!st.empty()) {
        int u = st.top();
        st.pop();

        cout << u << " ";
        sort(graph[u].rbegin(), graph[u].rend());
        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1);
    return 0;
}