#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        int count = 0;
        
        // Place elements less than pivot at the beginning
        for(int i = 0; i < n; ++i){
            if(nums[i] < pivot){
                res[left++] = nums[i];
            } else if(nums[i] == pivot){
                count++; // Count pivot elements
            }
        }
        
        // Fill the middle with pivot values
        for(int i = 0; i < count; ++i){
            res[left++] = pivot;
        }
        
        // Place elements greater than pivot at the end
        right = n - 1;
        for(int i = n - 1; i >= 0; --i){
            if(nums[i] > pivot){
                res[right--] = nums[i];
            }
        }
        
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> result = sol.pivotArray(nums, pivot);
    for(int x : result) cout << x << " ";
    return 0;
}