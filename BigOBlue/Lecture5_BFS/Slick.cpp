#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3823/problems/546?view=statement

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int N, int M) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M 
                && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                size++;
            }
        }
    }
    return size;
}

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vector<vector<int>> grid(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> grid[i][j];

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<int> sizes;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int sz = bfs(grid, visited, i, j, N, M);
                    sizes.push_back(sz);
                }
        sort(sizes.begin(), sizes.end());
        map<int, int> cnt;
        for (int sz : sizes) cnt[sz]++;
        cout << sizes.size() << endl;
        for (auto& [sz, c] : cnt) {
            cout << sz << " " << c << endl;
        }
    }
    return 0;
}