#include<iostream>
#include<vector>
#define MAX 1005
using namespace std;
const int INF = 1e9 + 7;

int M;
vector<string> matrix(MAX);
vector<vector<int>> dist(MAX, vector<int>(MAX));

void FloyWarshall() {
    for(int k = 0; k < M; k++) {
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < M; j++) {
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
        M = s.size();

        for(int i = 0; i < M; i++) {
            if(i == 0) {
                matrix[0] = s;
            } else {
                cin >> matrix[i];
            }
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == 'Y') {
                    dist[i][j] = 1;
                } else {
                    dist[i][j] = (i == j ? 0 : INF);    
                }
            }
        }

        FloyWarshall();
        int nfriends = 0, idx = 0;

        for(int i = 0; i < M; i++) {
            int count = 0;
            for(int j = 0; j < M; j++) {
                if(dist[i][j] == 2) {
                    count++;
                }
            }

            if(count > nfriends) {
                nfriends = count;
                idx = i;
            }
        }

        cout << idx << " " << nfriends << endl;
    }  
    return 0;
}