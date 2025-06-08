#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                vector<int> temp;
                for (int i = 0; i < l; ++i) temp.push_back(nums[i]);
                for (int i = r + 1; i < n; ++i) temp.push_back(nums[i]);
                bool ok = true;
                for (int i = 1; i < temp.size(); ++i) {
                    if (temp[i] <= temp[i - 1]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++res;
            }
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.incremovableSubarrayCount(nums) << endl;
    return 0;
}