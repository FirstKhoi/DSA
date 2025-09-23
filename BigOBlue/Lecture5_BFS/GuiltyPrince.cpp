#include<bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3823/problems/543?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int W, H;
        cin >> W >> H;
        vector<string> grid(H);
        pair<int, int> start;
        for (int i = 0; i < H; ++i) {
            cin >> grid[i];
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] == '@') {
                    start = {i, j};
                }
            }
        }
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        int cnt = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W &&
                    !visited[nx][ny] && (grid[nx][ny] == '.' || grid[nx][ny] == '@')) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    ++cnt;
                }
            }
        }
        cout << "Case " << tc << ": " << cnt << '\n';
    }
    return 0;
}