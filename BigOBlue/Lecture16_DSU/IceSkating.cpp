#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks;

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

bool makePair(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first == p2.first || p1.second == p2.second;
}


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    parent.assign(n + 1, 0);
    ranks.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        
        for(int j = 0; j < i; j++) {
            if(makePair(p[i], p[j]))
                unionSet(i, j);
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(findSet(i) == i) {
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}