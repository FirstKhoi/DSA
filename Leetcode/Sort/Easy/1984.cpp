#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/?envType=problem-list-v2&envId=sorting
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;
        for(int i = 0; i + k - 1 < nums.size(); i++){
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
            if(minDiff == 0) return 0; // Early return if we find the minimum possible difference
        }
        
        return minDiff;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;
    cout << sol.minimumDifference(nums, k) << '\n';
    return 0;
}