#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=problem-list-v2&envId=sliding-window
#include <cfloat>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();        
        if(n < k) return 0.0;
        double maxAvg = -DBL_MAX;
        double currentSum = 0.0;
        for(int i = 0; i < k; ++i) {
            currentSum += nums[i];       
        }
        maxAvg = max(maxAvg, currentSum / k);
        for(int i = k; i < n; ++i) {
            currentSum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, currentSum / k);
        }
        return maxAvg;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution sol;
    double result = sol.findMaxAverage(nums, k);
    cout << "Maximum average of subarray of size " << k << " is: " << result << endl;
    return 0;
}