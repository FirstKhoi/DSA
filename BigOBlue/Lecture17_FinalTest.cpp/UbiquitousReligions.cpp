#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks;

void makeSet(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 1;
    }
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
    } else if(ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        ranks[pu]++;
    }
}

int main() {
    int n, m, tc = 1;
    while(true) {
        cin >> n >> m;
        parent.assign(n + 1, 0);
        ranks.assign(n + 1, 0);
        if(n == 0 && m == 0) break;
        makeSet(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            unionSet(u, v);
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(parent[i] == i) {
                res++;
            }
        }
        cout << "Case " << tc++ << ": " << res << endl;
    }
    return 0;
}