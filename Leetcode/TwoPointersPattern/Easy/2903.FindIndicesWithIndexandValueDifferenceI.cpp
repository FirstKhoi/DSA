#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + indexDifference; j < n; j++) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}