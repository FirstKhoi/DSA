#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

vector<int> parent, ranks, cnt;
multiset<int> sizes;

int findSet(int u) {
    if(parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    if(pu == pv) return;

    sizes.erase(sizes.find(cnt[pu]));
    sizes.erase(sizes.find(cnt[pv]));

    if(ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
        cnt[pu] += cnt[pv];
        sizes.insert(cnt[pu]);
    }
    else if(ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
        cnt[pv] += cnt[pu];
        sizes.insert(cnt[pv]);
    } else {
        parent[pv] = pu;
        ranks[pu]++;
        cnt[pu] += cnt[pv];
        sizes.insert(cnt[pu]);
    }

}

int main() {
    int N, Q;
    cin >> N >> Q;

    parent.assign(N + 1, 0);
    ranks.assign(N + 1, 0);
    cnt.assign(N + 1, 1);

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        ranks[i] = 0;
        cnt[i] = 1;
        sizes.insert(1);
    }

    for(int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        unionSet(A, B);

        int maxSize = *sizes.rbegin();
        int minSize = *sizes.begin();

        if(sizes.size() == 1) cout << 0 << endl;
        else cout << maxSize - minSize << endl;
    }
    return 0;
}