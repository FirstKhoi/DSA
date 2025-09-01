#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 505
using namespace std;
const int INF = 1e9 + 7;

int n;
long long dist[MAX][MAX];
long long res[MAX];
int midV[MAX];

int main() {
    int u, v;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> midV[i];
    }

    for(int t = n - 1; t >= 0; t--) {
        int k = midV[t];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        for(int i = t; i < n; i++) {
            u = midV[i];
            for(int j = t; j < n; j++) {
                v = midV[j];
                res[t] += dist[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}