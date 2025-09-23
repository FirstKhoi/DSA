#include<iostream>
#include<vector>
#define MAX 48
const int INF = 1e9 + 7;
using namespace std;

int dist[MAX + 1][MAX + 1];

void floyWarshall() {
    for(int k = 0; k <= MAX; k++) {
        for(int i = 0; i <= MAX; i++) {
            for(int j = 0; j <= MAX; j++) {
                if(i <= k && k <= j) {
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int T, N, S, E, C;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i <= MAX; i++) {
            for(int j = 0; j <= MAX; j++) {
                dist[i][j] = 0;
            }
        }

        for(int i = 0; i < N; i++) {
            cin >> S >> E >> C;
            if(C > dist[S][E]) {
                dist[S][E] = C;
            }
        }

        floyWarshall();
        cout << dist[0][MAX] << endl;
    }
    return 0;
}