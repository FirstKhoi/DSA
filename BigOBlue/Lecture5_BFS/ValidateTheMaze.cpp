#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 21

// Problem: Validate the Maze
// We need to check if there's a valid path between two entrance points in a maze

int n, m;
string maze[MAX];
bool visited[MAX][MAX];

// Direction vectors for moving up, down, left, right
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

struct Cell {
    int r, c;
};

// Check if a cell is valid to visit
bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == '.' && !visited[r][c];
}

// BFS to find path between start and finish
bool bfs(const Cell& start, const Cell& finish) {
    // Reset visited array
    memset(visited, false, sizeof(visited));
    
    queue<Cell> q;
    q.push(start);
    visited[start.r][start.c] = true;
    
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();
        
        if (curr.r == finish.r && curr.c == finish.c) 
            return true;
        
        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i], nc = curr.c + dc[i];
            if (isValid(nr, nc)) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    return false;
}

bool isBoundary(int r, int c) {
    return r == 0 || r == n-1 || c == 0 || c == m-1;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> maze[i];

        vector<Cell> entrances;
        
        // Find all cells on the boundary that are passage ('.')
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == '.' && isBoundary(i, j)) {
                    entrances.push_back({i, j});
                }
            }
        }

        // A valid maze has exactly 2 entrances
        if (entrances.size() != 2) {
            cout << "invalid\n";
        } else {
            const Cell& start = entrances[0];
            const Cell& finish = entrances[1];
            
            // Check if there's a path between the entrances
            cout << (bfs(start, finish) ? "valid" : "invalid") << endl;
        }
    }
    return 0;
}
