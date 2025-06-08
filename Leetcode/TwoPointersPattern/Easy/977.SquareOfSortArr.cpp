#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=problem-list-v2&envId=array
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n); // Khai báo vector kết quả với kích thước n
        int l = 0, r = n - 1;
        
        for (int i = n - 1; i >= 0; --i) {
            if (abs(nums[l]) > abs(nums[r])) {
                res[i] = nums[l] * nums[l]; // Bình phương phần tử bên trái
                l++;
            } else {
                res[i] = nums[r] * nums[r]; // Bình phương phần tử bên phải
                r--;
            }
        }
        
        return res; // Trả về vector kết quả
    }
};

    return 0;
}