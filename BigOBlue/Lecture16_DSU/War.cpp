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

int main() {
    int n, c, x, y;
    cin >> n;
    parent.assign(2 * n + 1, 0);
    ranks.assign(2 * n + 1, 0);
    for(int i = 1; i <= 2 * n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
    while(true) {
        cin >> c >> x >> y;
        if(c == 0 && x == 0 && y == 0) {
            break;
        }
        if(c == 1) {
            if(findSet(x) == findSet(y + n)) {
                cout << -1 << endl;
                continue;
            }
            unionSet(x, y);
            unionSet(x + n, y + n);
        } else if(c == 2) {
            if(findSet(x) == findSet(y)) {
                cout << -1 << endl;
                continue;
            }
            unionSet(x, y + n);
            unionSet(x + n, y);
        } else if(c == 3) {
            cout << (findSet(x) == findSet(y)) << endl;
        } else if(c == 4) {
            cout <<(findSet(x) == findSet(y + (n))) << endl;
        }
    }
    return 0;
}