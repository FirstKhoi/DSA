#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int c; cin >> c;
    while(c--){
        int n, t, m; cin >> n >> t >> m;
        queue<pair<int, int>> left, right;
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int arrival;
            string side;
            cin >> arrival >> side;
            if (side == "left")
                left.push({arrival, i});
            else
                right.push({arrival, i});
        }
        int time = 0, pos = 0; // 0: left, 1: right
        while (!left.empty() || !right.empty()) {
            int next_left = left.empty() ? INT_MAX : left.front().first;
            int next_right = right.empty() ? INT_MAX : right.front().first;
            int next_arrival = min(next_left, next_right);
            if (next_arrival > time && 
                ((pos == 0 && left.empty()) || (pos == 1 && right.empty()))) {
                time = next_arrival;
            }
            queue<pair<int, int>>& cur = (pos == 0 ? left : right);
            int cnt = 0;
            vector<pair<int, int>> load;
            while (!cur.empty() && cur.front().first <= time && cnt < n) {
                load.push_back(cur.front());
                cur.pop();
                ++cnt;
            }
            for (auto& car : load) {
                ans[car.second] = time + t;
            }
            if (cnt > 0 || (!left.empty() && next_left <= time) || (!right.empty() && next_right <= time)) {
                time += t;
                pos ^= 1;
            } else {
                time = min(next_left, next_right);
            }
        }
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << '\n'; 
        }
        if (c) cout << '\n';
    }
    return 0;
}