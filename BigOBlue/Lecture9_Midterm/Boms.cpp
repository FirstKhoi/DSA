#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int bfs(vector<vector<int>>& grid, Point start, Point end) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dist(R, vector<int>(C, -1));
        queue<Point> q;

        dist[start.x][start.y] = 0;
        q.push(start);

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist[end.x][end.y];
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        while (true) {
            int R, C;
            cin >> R >> C;
            if (R == 0 && C == 0) break;

            vector<vector<int>> grid(R, vector<int>(C, 0));

            int rows;
            cin >> rows;
            for (int i = 0; i < rows; ++i) {
                int row, bombs;
                cin >> row >> bombs;
                for (int j = 0; j < bombs; ++j) {
                    int col;
                    cin >> col;
                    grid[row][col] = 1;
                }
            }

            Point start, end;
            cin >> start.x >> start.y >> end.x >> end.y;

            int result = bfs(grid, start, end);
            cout << result << '\n';
        }

        return 0;
    }
