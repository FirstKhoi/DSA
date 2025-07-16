#include<iostream>
#include<stack>
#include<vector>
#define MAX 51
using namespace std;

const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int w, h, res;
char graph[MAX][MAX];
int visited[MAX][MAX];

bool valid(int r, int c) {
    return r >= 0 && c >= 0 && r < h && c < w;
}

int DFS(int sr, int sc) {
    int count = 0;
    
    for(int i = 0; i < 8; i++) {
        int r = sr + dx[i];
        int c = sc + dy[i];

        if(valid(r, c) && graph[r][c] - graph[sr][sc] == 1 && visited[r][c] == 0) {
            DFS(r, c);
            count = max(count, visited[r][c]);
        }
    }

    visited[sr][sc] = count + 1;
    return visited[sr][sc];
}

int main() {
    int t = 1;
    while(true) {
        int res = 0;
        cin >> h >> w;
        if(h == 0 && w == 0) {
            break;
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> graph[i][j];
                visited[i][j] = 0;
            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(graph[i][j] == 'A') {
                    res = max(res, DFS(i, j));
                }
            }
        }

        cout << "Case" << t++ << ": " << res << endl;
    }
    return 0;
}