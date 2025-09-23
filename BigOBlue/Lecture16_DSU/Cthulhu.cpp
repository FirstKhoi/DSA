#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks;

void makeSet(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int u) {
    if(parent[u] != u) findSet(parent[u]);
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
    int n, m;
    cin >> n >> m;
    
    parent.assign(n + 1, 0);
    ranks.assign(n + 1, 0);
    
    makeSet(n);

    if(n != m) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unionSet(u, v);
    }

    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(parent[i] == i) {
            components++;
        }
    }
    cout << (components == 1 && n == m && n >= 3 ? "FHTAGN!" : "NO") << endl;
    
    return 0;
}