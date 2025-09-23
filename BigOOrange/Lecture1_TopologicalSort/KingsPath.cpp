#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int x0, y0, x1, y1, n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    
    set<pair<int,int>> allowed;
    for(int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++) {
            allowed.insert({r, j});
        }
    }
    
    queue<pair<int,int>> q;
    map<pair<int,int>, int> dist;
    
    q.push({x0, y0});
    dist[{x0, y0}] = 0;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if(x == x1 && y == y1) {
            cout << dist[{x, y}] << endl;
            return 0;
        }
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 1 && nx <= 1e9 && ny >= 1 && ny <= 1e9 && 
               allowed.count({nx, ny}) && !dist.count({nx, ny})) {
                dist[{nx, ny}] = dist[{x, y}] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}