#include<iostream>
#include<queue>
#include<vector>
#define MAX 255
using namespace std;

int N, M;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int dist[MAX * MAX];
int grid[MAX][MAX];

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}

void BFS(Cell s) {
    queue<Cell> q;
    q.push(s);
    grid[s.r][s.c] = 0;
    int count = 1;

    while(!q.empty()) {
        Cell u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if(isValid(r, c) && grid[r][c] == 1) {
                grid[r][c] = 0;
                q.push((Cell) {r, c});
                count++;
            }
        }
    }
    dist[count]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) {
            break;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> grid[i][j];
                dist[i * M + j + 1] = 0;
            }
        }

        int nSlicks = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 1) {
                    nSlicks++;
                    BFS((Cell) {i, j});
                }
            }
        }

        cout << nSlicks << endl;
        
        for(int i = 1; i <= N * M; i++) {
            if(dist[i]) {
                cout << i << " " << dist[i] << endl;
            }
        }
    }
    return 0;
}