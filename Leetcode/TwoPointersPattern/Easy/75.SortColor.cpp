#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/sort-colors/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;
        while(mid <= r) {
            if (nums[mid] == 0) {
                swap(nums[l++], nums[mid++]);
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[r--]);
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}