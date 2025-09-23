#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 55
const int INF = 1e9 + 7;
using namespace std;

int m;
int dist[MAX][MAX];
string matrix[MAX]; 

void floyWarshall() {
    for(int k = 0; k < m; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        m = s.length();

        for(int i = 0; i < m; i++) {
            if(i == 0) {
                matrix[0] = s;
            } else {
                cin >> matrix[i];
            }

                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == 'Y') {
                        dist[i][j] = 1;
                    } else {
                        dist[i][j] = (i == j ? 0 : INF);
                    }
                }
        }

        floyWarshall();
        int countFr = 0, index = 0;

        for(int i = 0; i < m ; i++) {
            int count = 0;

            for(int j = 0; j < m; j++) {
                if(dist[i][j] == 2) {
                    count++;
                }
            }

            if(count > countFr) {
                countFr = count;
                index = i;
            }
        }
        cout << index << " " << countFr << endl;
    }
    return 0;
}

