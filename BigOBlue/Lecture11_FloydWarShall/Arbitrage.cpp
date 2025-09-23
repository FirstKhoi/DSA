#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 35
const int INF = 1e9 + 7;

string currcies[MAX];
double dist[MAX][MAX];
int n, m;

void floyWarshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
            }
        }
    }
}

int currency(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(currcies[i] == s) {
            return i;
        }
    }
    return -1;
}


int main() {
    string u, v;
    int tc = 1;
    double w;
    while(true) {
        cin >> n;
        if(n == 0) break;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = 0;
                if(i == j) dist[i][j] = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            cin >> currcies[i];

            cin >> m;
            for(int j = 0; j < m; j++) {
                cin >> u >> v >> w;
                dist[currency(u)][currency(v)] = w;
            }
        }
        floyWarshall();
        bool check = false;
        for(int i = 0; i < n; i++) {
            if(dist[i][i] > 1) {
                check = true;
                break;
            }
        }
        cout << "Case " << tc++ << ": " << (check ? "YES" : "NO") << endl;
    }
    return 0;
}