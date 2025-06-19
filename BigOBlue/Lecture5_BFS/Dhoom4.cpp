#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int start, target;
    cin >> start >> target;
    int n;
    cin >> n;
    vector<int> keys(n);
    for (int i = 0; i < n; ++i) cin >> keys[i];

    const int MOD = 100000;
    vector<int> dist(MOD, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == target) {
            cout << dist[curr] << '\n';
            return 0;
        }
        for (int k : keys) {
            int next = (1LL * curr * k) % MOD;
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}