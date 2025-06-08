#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == 0) {
                return nums[right];
            } else if (abs(nums[left]) > abs(nums[right])) {
                left++;
            } else {
                right--;
            }
        }
        return -1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {-1, 2, -3, 3, 1};
    int result = sol.findMaxK(nums);
    cout << result << endl; // 3
    return 0;
}