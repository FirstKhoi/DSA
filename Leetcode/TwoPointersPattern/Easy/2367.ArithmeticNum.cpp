#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
// https://leetcode.com/problems/number-of-arithmetic-triplets/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;
        
        // Since the array is sorted, we can use two pointers approach
        for (int j = 0; j < n; j++) {
            int i = 0;
            int k = j + 1;
            
            while (i < j && k < n) {
                if (nums[j] - nums[i] > diff) {
                    // If the difference is too large, move i forward
                    i++;
                } else if (nums[j] - nums[i] < diff) {
                    // If the difference is too small, we can't fix it, break
                    break;
                } else if (nums[k] - nums[j] > diff) {
                    // If the difference is too large, we can't fix it, break
                    break;
                } else if (nums[k] - nums[j] < diff) {
                    // If the difference is too small, move k forward
                    k++;
                } else {
                    // We found a triplet
                    count++;
                    k++;
                }
            }
        }
        return count;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {0, 1, 4, 6, 7, 10};
    int diff = 3;
    int result = sol.arithmeticTriplets(nums, diff);
    cout << result << endl;
    return 0;
}