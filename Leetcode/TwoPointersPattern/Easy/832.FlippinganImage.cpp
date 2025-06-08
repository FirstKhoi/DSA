#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/flipping-an-image/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; ++i){
            reverse(image[i].begin(), image[i].end());
            for(int j = 0; j < n; ++j){
                image[i][j] = image [i][j] == 0 ? 1 : 0;
            }
        }
        return image;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> result = sol.flipAndInvertImage(image);
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    return 0;
}