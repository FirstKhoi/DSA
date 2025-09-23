#include<iostream>
#include<stack>
#include<vector>
#define MAX 1000005
using namespace std;

int V, E;
bool visited[MAX];
vector<int> graph[MAX];

void DFS(int s) {
    stack<int> st;
    visited[s] = true;
    st.push(s);

    while(!st.empty()) {
        int u = st.top();
        st.pop();

        for(int &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q, u, v;
    cin >> Q;
    while(Q--) {
        cin >> V >> E;
        for(int i = 0; i < V; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                count++;
                DFS(i);
            }
        }
        cout << count << endl;
    }
    return 0;
}