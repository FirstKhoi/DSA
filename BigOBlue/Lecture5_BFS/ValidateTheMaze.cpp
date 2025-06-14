#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 21
//https://bigocoder.com/courses/252/lectures/3823/problems/541?view=statement
int n, m;
string maze[MAX];
bool visited[MAX][MAX];

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == '.' && !visited[r][c];
}

bool dfs(int r, int c, int fr, int fc) {
    if (r == fr && c == fc) return true;
    visited[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (isValid(nr, nc)) {
            if (dfs(nr, nc, fr, fc)) return true;
        }
    }
    return false;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> maze[i];

        vector<Cell> entrance;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                visited[i][j] = false;
                if (maze[i][j] == '.' && (i == 0 || j == 0 || i == n-1 || j == m-1))
                    entrance.push_back({i, j});
            }

        if (entrance.size() != 2) cout << "invalid\n";
        else {
            Cell s = entrance[0], f = entrance[1];
            cout << (dfs(s.r, s.c, f.r, f.c) ? "valid" : "invalid") << endl;
        }
    }
    return 0;
}
