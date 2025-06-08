#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/sort-array-by-parity-ii/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int even = 0, odd = 1;
        for(int i = 0; i < n; ++i){
            if(nums[i] % 2 == 0){
                res[even] = nums[i];
                even += 2;
            } else {
                res[odd] = nums[i];
                odd += 2;
            }
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {4, 2, 5, 7};
    vector<int> result = sol.sortArrayByParityII(nums);
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}