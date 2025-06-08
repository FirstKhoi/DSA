#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/1648684926/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int posIndex = 0, negIndex = 1;
        
        for (int num : nums) {
            if (num > 0) {
                result[posIndex] = num;
                posIndex += 2;
            } else {
                result[negIndex] = num;
                negIndex += 2;
            }
        }
        
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> result = sol.rearrangeArray(nums);
    for(int i : result) cout << i << " ";
    return 0;
}