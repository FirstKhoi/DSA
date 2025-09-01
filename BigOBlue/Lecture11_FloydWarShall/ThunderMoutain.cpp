#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#define MAX 105
const int INF = 2049;
using namespace std;

int n;
int x[MAX],  y[MAX];
double dist[MAX][MAX];

double Distance(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void floyWarshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N; cin >> N;
    for(int t = 1; t <= N; t++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) 
                    dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                double d = Distance(i, j);

                if(d <= 10) dist[i][j] = d;
            }
        }

        floyWarshall();
        double ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dist[i][j]);
            }
        }

        cout << "Case #" << t << ":" << endl;
        if(ans != INF) {
            cout << fixed << setprecision(4) << ans << endl;
        }
        else {
            cout << "Send Kurdy" << endl;
        }

        cout << endl;
    }

    return 0;
}