#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/sort-array-by-parity/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       int i = 0, j = nums.size() - 1;
    while (i < j) {
        while (i < j && nums[i] % 2 == 0) i++;
        while (i < j && nums[j] % 2 == 1) j--;
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
        return nums;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {3, 1, 2, 4};
    vector<int> sorted = sol.sortArrayByParity(nums);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}