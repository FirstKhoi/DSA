#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks, cnt;

void makeSet(int N) {
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        ranks[i] = 0;
        cnt[i] = 1;
    }
} 

int findSet(int u) {
    if(parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);

    if(pu == pv) return;

    else if(ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
        cnt[pu] += cnt[pv];
    } else if(ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
        cnt[pv] += cnt[pu];
    } else {
        parent[pv] = pu;
        cnt[pu] += cnt[pv];
        ranks[pu]++;
    }
}

int main() {
    int T, N, M;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        parent.assign(N + 1, 0);
        cnt.assign(N + 1, 0);
        ranks.assign(N + 1, 0);
        makeSet(N);
        for(int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            unionSet(u, v);
        }
        int res = 1;
        for(int i = 1; i <= N; i++) {
            if(parent[i] == i)
                res = max(res, cnt[i]);
        }
        cout << res << endl;
    }
    return 0;
}