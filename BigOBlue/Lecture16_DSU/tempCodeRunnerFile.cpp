#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> parent, ranks;

void makeSet(int N) {
    parent.assign(N + 1, 0);
    ranks.assign(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        ranks[i] = 0;
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

int main () {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        if(t > 0) cout << endl;

        string line;
        getline(cin, line);
        char maxChar = line[0];
        
        vector<string> edges;
        while(getline(cin, line) && !line.empty()) {
            edges.push_back(line);
            if(line.length() >= 1) maxChar = max(maxChar, line[0]);
            if(line.length() >= 2) maxChar = max(maxChar, line[1]);
        }
        
        int n = maxChar - 'A' + 1;
        makeSet(n);

        for(const string& edge : edges) {
            if(edge.length() >= 2) {
                int u = edge[0] - 'A' + 1;
                int v = edge[1] - 'A' + 1;
                unionSet(u, v);
            }
        }

        int components = 0;
        for(int i = 1; i <= n; i++) {
            if(parent[i] == i) components++;
        }
        cout << components << endl;
    }
    return 0;
}