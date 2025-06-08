#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=problem-list-v2&envId=sorting
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> num_idx;
        for (int i = 0; i < nums.size(); ++i) {
            num_idx.push_back({nums[i], i});
        }
        sort(num_idx.rbegin(), num_idx.rend());
        vector<int> idxs;
        for (int i = 0; i < k; ++i) {
            idxs.push_back(num_idx[i].second);
        }
        sort(idxs.begin(), idxs.end());
        vector<int> res;
        for (int i : idxs) {
            res.push_back(nums[i]);
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}