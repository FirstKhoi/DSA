//https://codeforces.com/problemset/problem/755/C
#include <iostream>
#include <vector>
#include <stack>
#define MAX 10005
using namespace std;

vector<int> adj[MAX];
vector<bool> visited(MAX);

void dfs(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while(!st.empty()) {
        int u = st.top(); st.pop();
        
        int cnt = 0;
        for(int &v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                cnt++;
                st.push(v);
                
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}