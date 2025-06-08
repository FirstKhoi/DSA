#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int cnt = grid[i][j] + grid[n - i - 1][j] + grid[i][m - j - 1] + grid[n - i - 1][m - j - 1];
                ans += min(cnt, 4 - cnt);
            }
        }
        if (n % 2) {
            for (int j = 0; j < m / 2; ++j) {
                int cnt = grid[n / 2][j] + grid[n / 2][m - j - 1];
                ans += min(cnt, 2 - cnt);
            }
        }
        if (m % 2) {
            for (int i = 0; i < n / 2; ++i) {
                int cnt = grid[i][m / 2] + grid[n - i - 1][m / 2];
                ans += min(cnt, 2 - cnt);
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<vector<int>> grid = {{0,1,0},{1,0,1},{0,1,0}};
    cout << sol.minFlips(grid) << endl;
    return 0;
}