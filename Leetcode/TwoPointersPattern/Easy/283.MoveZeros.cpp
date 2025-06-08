#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/move-zeroes/description/?envType=problem-list-v2&envId=array
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = 1;
        while(r < n){
            if(nums[l] != 0){
                l++;
                r++;
            } else if (nums[r] == 0){
                r++;
            } else{
                int temp = nums[r];
                nums[r] = nums[l];
                nums[l] = temp;
            }
        }
    }
};
    return 0;
}