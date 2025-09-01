#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
const int MAX = 10005;
using namespace std;

int V, E;
vector<int> graph[MAX];
bool visited[MAX];

int DFS(int s) {
    stack<int> st;
    int count = 0;
    visited[s] = true;
    st.push(s);

    while(!st.empty()) {
        int u = st.top();
        st.pop();
        count++;
        for(auto &v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<int> boms(n);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int max_bombs = 0;
    for(int i = 1; i <= n; i++) {
        fill(visited, visited + MAX, false);
        max_bombs = max(max_bombs, DFS(i));
    }
    cout << max_bombs << endl;
    return 0;
}