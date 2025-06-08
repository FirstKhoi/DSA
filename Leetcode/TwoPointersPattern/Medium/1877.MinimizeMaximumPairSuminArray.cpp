#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        int maxPairSum = 0;
        while (left < right) {
            maxPairSum = max(maxPairSum, nums[left] + nums[right]);
            ++left;
            --right;
        }
        return maxPairSum;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}