#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> parent, ranks;

void init(int n) {
    parent.assign(n, 0);
    ranks.assign(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
}

int findSet(int u) {
    if(parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    if(pu == pv) return;
    if(ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
    } else if(ranks[pv] > ranks[pu]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        ranks[pu]++;
    }
}

int main() {
    int T;
    string line;
    getline(cin, line);
    T = stoi(line);
    getline(cin, line);

    for(int test = 0; test < T; test++) {
        getline(cin, line);
        int n = line[0] - 'A' + 1;
        init(n);

        while(getline(cin, line)) {
            if(line.empty()) break;
            int u = line[0] - 'A';
            int v = line[1] - 'A';
            unionSet(u, v);
        }

        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int root = findSet(i);
            if(!vis[root]) {
                ans++;
                vis[root] = true;
            }
        }
        cout << ans << endl;
        if(test != T-1) cout << endl;
    }
    return 0;
}